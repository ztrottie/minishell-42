#include "../../include/execution.h"

static int	input_redirection_choice(t_data *data, t_red *red, t_files *file)
{
	file->here_doc = false;
	if (red->type == RED_IN)
		file->name = red->content;
	else
	{
		file->here_doc = true;
		if (here_doc_main(data, red, &file->name, false) <= 0)
			return (FAILURE);
	}
	file->fd = open(file->name, O_RDONLY);
	file->input = true;
	return (SUCCESS);
}

static void	output_redirection_choice(t_red *red, t_files *file)
{
	file->input = false;
	file->here_doc = false;
	file->name = red->content;
	if (red->type == RED_OUT)
		file->fd = open(file->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		file->fd = open(file->name, O_CREAT | O_WRONLY | O_APPEND, 0644);
}

static int redirection_choice(t_data *data, t_red *red, t_files *file)
{
	if (red->type == HERE_DOC || red->type == RED_IN)
	{
		if (input_redirection_choice(data, red, file) <= 0)
			return (FAILURE);
	}
	else
		output_redirection_choice(red, file);
	return (SUCCESS);
}

static int	add_redirection(t_data *data, t_files *file, int index)
{
	t_files	**choice;

	if (file->input)
		choice = &data->cmds[index].input;
	else
		choice = &data->cmds[index].output;
	if (file_add_end(choice, file->fd, file->name, file->here_doc) <= 0)
		return (FAILURE);
	return (SUCCESS);
}

static int	find_next_red(bool input, t_red *red)
{
	t_red *ptr;

	ptr = red;
	while (red != NULL)
	{
		if (input)
		{
			if (ptr->type == HERE_DOC || ptr->type == RED_IN)
				return (VALID);
		}
		else
			if (ptr->type == RED_OUT || ptr->type == RED_OUT_APPEND)
				return (VALID);
		ptr = ptr->next;
	}
	return (INVALID);
}

static int	next_red(t_data *data, int index, t_red **ptr, t_files *file)
{
	if (find_next_red(file->input, *ptr) == INVALID)
	{
		if (add_redirection(data, file, index) <= 0)
			return (FAILURE);
	}
	else
	{
		close(file->fd);
		if (file->here_doc)
			unlink(file->name);
	}
	*ptr = (*ptr)->next;
	return (SUCCESS);
}

static int	open_redirection(t_data *data, size_t index)
{
	t_red	*ptr;
	t_files	file;

	ptr = data->cmds[index].red;
	while (ptr != NULL)
	{
		if (redirection_choice(data, ptr, &file) <= 0)
			return(FAILURE);
		if (next_red(data, index, &ptr, &file) <= 0)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	convert_redirection(t_data *data)
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
