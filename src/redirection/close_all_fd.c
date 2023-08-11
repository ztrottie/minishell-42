#include "../../include/redirection.h"

static int	close_files(t_files **files, bool parent)
{
	t_files	*ptr;

	ptr = *files;
	while (ptr != NULL)
	{
		if (ptr->fd > 0)
		{
			if (close(ptr->fd) < 0)
				return (print_error("close"), FAILURE);
			if (parent && ptr->here_doc)
				if (unlink(ptr->name) < 0)
					return (FAILURE);
		}
		ptr = ptr->next;
	}
	return (SUCCESS);
}

int	close_all(t_data *data, bool parent)
{
	size_t	i;

	i = 0;
	while (i < data->nb_pipe + 1)
	{
		if (close_files(&data->cmds[i].input, parent) <= 0)
			return (FAILURE);
		if (close_files(&data->cmds[i].output, parent) <= 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
