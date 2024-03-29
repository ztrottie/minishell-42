/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:20:46 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:20:47 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/redirection.h"

int	file_add_end(t_files **files, int fd, char *name, bool here_doc)
{
	t_files	*ptr;

	if (!*files)
	{
		*files = ft_calloc(1, sizeof(t_files));
		if (!*files)
			return (print_error("malloc"), FAILURE);
		(*files)->fd = fd;
		(*files)->name = name;
		(*files)->here_doc = here_doc;
	}
	else
	{
		ptr = *files;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = ft_calloc(1, sizeof(t_files));
		if (!ptr->next)
			return (print_error("malloc"), FAILURE);
		ptr->next->fd = fd;
		ptr->next->name = name;
		ptr->next->here_doc = here_doc;
	}
	return (SUCCESS);
}

int	free_files(t_files **files)
{
	t_files	*ptr;
	t_files	*tmp;

	ptr = *files;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		if (ptr->here_doc)
			ft_free(ptr->name);
		ft_free(ptr);
		ptr = tmp;
	}
	*files = NULL;
	return (SUCCESS);
}
