#include "../../include/execution.h"

static int	open_pipes(t_data *data)
{
	size_t	i;
	int		end[2];

	i = 0;
	while (i < data->nb_pipe)
	{
		if (pipe(end) < 0)
			return (FAILURE);
		if (file_add_end(&data->cmds[i].output, end[1], NULL, false) <= 0 \
		|| file_add_end(&data->cmds[i + 1].input, end[0], NULL, false) <= 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int	redirection_choice(t_data *data, t_red *ptr, size_t index)
{
	int		fd;
	t_files	**files;

	if (ptr->type == RED_IN)
	{
		fd = open(ptr->content, O_RDONLY);
		files = &data->cmds[index].input;
	}
	else if (ptr->type == HERE_DOC)
	{
		if (here_doc_main(data, &data->cmds[index].input, ptr) <= 0)
			return (FAILURE);
	}
	else if (ptr->type == RED_OUT || ptr->type == RED_OUT_APPEND)
	{
		if (ptr->type == RED_OUT)
			fd = open(ptr->content, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		else
			fd = open(ptr->content, O_WRONLY | O_APPEND | O_CREAT, 0644);
		files = &data->cmds[index].output;
	}
	if (ptr->type != HERE_DOC)
		if (file_add_end(files, fd, ptr->content, false) <= 0)
			return (FAILURE);
	return (SUCCESS);
}

static int	open_redirection(t_data *data, size_t index)
{
	t_red *ptr;

	ptr = data->cmds[index].red;
	while (ptr != NULL)
	{
		if (redirection_choice(data, ptr, index) <= 0)
			return(FAILURE);
		ptr = ptr->next;
	}
	return (SUCCESS);
}

static int	convert_redirection(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_pipe + 1)
	{
		if (open_redirection(data, i) <= 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int	std_redirection(t_data *data)
{
	if (data->nb_pipe > 0)
		if (open_pipes(data) <= 0)
			return (FAILURE);
	if (convert_redirection(data) <= 0)
		return (FAILURE);
	return (SUCCESS);
}

int	redirection_main(t_data *data, int mode)
{
	if (mode == STD)
	{
		if (std_redirection(data) <= 0)
			return (FAILURE);
	}
	if (mode == ERROR)
		if (error_redirection(data) <= 0)
			return (FAILURE);
	return (SUCCESS);
}
