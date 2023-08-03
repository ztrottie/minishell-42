#include "../../include/execution.h"

static int	invalid_fd(int exit_code, t_files *file)
{
	if (exit_code != INVALID)
	{
		file->fd = -1;
		errno = ENOENT;
	}
	perror(file->name);
	return (INVALID);
}

static int	check_exit_code(t_data *data, int exit_code, t_files *file)
{
	struct stat	info;

	if (exit_code != INVALID)
		file->fd = open(file->name, O_RDONLY);
	if (file->fd < 0 || exit_code == INVALID)
		return (invalid_fd(exit_code, file));
	if (file->here_doc)
	{
		if (fstat(file->fd, &info) < 0)
			return (FAILURE);
		if (info.st_mtimespec.tv_sec != data->info_last_hd.st_mtimespec.tv_sec \
		|| info.st_mtimespec.tv_nsec != data->info_last_hd.st_mtimespec.tv_nsec)
			return (invalid_fd(SUCCESS, file));
	}
	return (SUCCESS);
}

static int	input_redirection_choice(t_data *data, t_red *red, t_files *file)
{
	int			exit_code;

	file->here_doc = false;
	exit_code = SUCCESS;
	if (red->type == RED_IN)
		file->name = red->content;
	else
	{
		file->here_doc = true;
		exit_code = here_doc_main(data, red, &file->name, false);
		if (exit_code == FAILURE)
			return (exit_code);
	}
	return (check_exit_code(data, exit_code, file));
}

static int	output_redirection_choice(t_red *red, t_files *file)
{
	file->input = false;
	file->here_doc = false;
	file->name = red->content;
	if (red->type == RED_OUT)
		file->fd = open(file->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		file->fd = open(file->name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (file->fd < 0)
		return (INVALID);
	return (VALID);
}

static int redirection_choice(t_data *data, t_red *red, t_files *file)
{
	if (red->type == HERE_DOC || red->type == RED_IN)
		return (input_redirection_choice(data, red, file));
	else
		return (output_redirection_choice(red, file));
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
	while (ptr != NULL)
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
	if (ptr == NULL)
		return (VALID);
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
	int		exit_code;

	ptr = data->cmds[index].red;
	while (ptr != NULL)
	{
		exit_code = redirection_choice(data, ptr, &file);
		if (exit_code == FAILURE)
			return (FAILURE);
		else if (exit_code == INVALID)
		{
			if (add_redirection(data, &file, index) <= 0)
				return (FAILURE);
			return (INVALID);
		}
		else
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
		if (open_redirection(data, i) < 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
