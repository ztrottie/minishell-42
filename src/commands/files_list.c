#include "../../include/commands.h"

int	file_add_end(t_files **files, char *name, int fd)
{
	t_files	*ptr;

	ptr = *files;
	if (!ptr)
	{
		ptr = ft_calloc(1, sizeof(t_files));
		if (!ptr)
			return (FAILURE);
		ptr->name = name;
		ptr->fd = fd;
	}
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = ft_calloc(1, sizeof(t_files));
		if (!ptr->next)
			return (FAILURE);
		ptr->next->name = name;
		ptr->next->fd = fd;
	}
	return (SUCCESS);
}

void	files_free(t_files **files)
{
	t_files *tmp;
	t_files *ptr;

	ptr = *files;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		ft_free(ptr->name);
		ft_free(ptr);
		ptr = tmp;
	}
	*files = NULL;
}
