/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:19:52 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:19:53 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

int	dup_files(t_files *files, int new_fd)
{
	if (!files)
		return (SUCCESS);
	else
	{
		if (files->fd < 0)
			return (FAILURE);
		if (files->next)
		{
			files = files->next;
			if (files->fd < 0)
				return (FAILURE);
		}
		if (dup2(files->fd, new_fd) < 0)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	get_in_out(t_data *data, t_cmds *cmds)
{
	if (dup_files(cmds->input, STDIN_FILENO) <= 0 \
	|| dup_files(cmds->output, STDOUT_FILENO) <= 0)
		return (FAILURE);
	if (close_all(data, false) <= 0)
		exit_child(data, 1);
	return (SUCCESS);
}
