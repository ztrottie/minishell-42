#include "../../include/execution.h"

static int	invalid_fd(t_files *file)
{
	file->fd = -1;
	errno = ENOENT;
	perror(file->name);
	return (INVALID);
}

static int	check_exit_code(t_data *data, int exit_code, t_files *file)
{
	struct stat	info;

	file->fd = open(file->name, O_RDONLY);
	if (file->fd < 0)
	{
		data->exit_code = 1;
		return (perror(file->name), INVALID);
	}
	if (file->here_doc)
	{
		if (fstat(file->fd, &info) < 0)
			return (FAILURE);
		if (info.st_mtimespec.tv_nsec != data->info_last_hd.st_mtimespec.tv_nsec \
		|| info.st_mtimespec.tv_sec != data->info_last_hd.st_mtimespec.tv_sec)
			return ();
	}
	return (SUCCESS);
}
int	input_redirection_choice(t_data *data, t_red *red, t_files *file)
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
