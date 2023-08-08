#include "../../include/redirection.h"

static int	invalid_fd(t_files *file)
{
	file->fd = -1;
	errno = ENOENT;
	perror(file->name);
	return (INVALID);
}

static int	check_exit_code(t_data *data, t_files *file)
{
	struct stat	info;

	if (file->here_doc)
	{
		if (access(file->name, F_OK) == 0)
		{
			if (stat(file->name, &info) < 0)
				return (FAILURE);
			if (info.st_mtimespec.tv_nsec != data->info_last_hd.st_mtimespec.tv_nsec \
			|| info.st_mtimespec.tv_sec != data->info_last_hd.st_mtimespec.tv_sec)
				return (invalid_fd(file));
		}
	}
	file->fd = open(file->name, O_RDONLY);
	if (file->fd < 0)
		return (data->exit_code = 1, perror(file->name), INVALID);
	return (SUCCESS);
}
int	input_redirection_choice(t_data *data, t_red *red, t_files *file)
{
	file->input = true;
	file->here_doc = false;
	if (red->type == RED_IN)
		file->name = red->content;
	else
	{
		file->here_doc = true;
		here_doc_main(data, red, &file->name, false);
	}
	return (check_exit_code(data, file));
}
