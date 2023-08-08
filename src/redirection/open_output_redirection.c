#include "../../include/redirection.h"

int	output_redirection_choice(t_red *red, t_files *file)
{
	file->input = false;
	file->here_doc = false;
	file->name = red->content;
	if (red->type == RED_OUT)
		file->fd = open(file->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		file->fd = open(file->name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (file->fd < 0)
		return (perror(file->name), INVALID);
	return (VALID);
}
