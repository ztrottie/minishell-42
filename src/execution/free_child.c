/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:19:46 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:19:47 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

static void	free_cmds(t_data *data, size_t cmd_nb)
{
	size_t	i;

	i = 0;
	while (i < data->nb_pipe + 1)
	{
		if (i != cmd_nb)
			data->cmds[i].content = ft_x2free((void **)data->cmds[i].content);
		free_red_list(&data->cmds[i].red);
		free_files(&data->cmds[i].input);
		free_files(&data->cmds[i].output);
		i++;
	}
}

void	free_child(t_data *data, size_t cmd_nb)
{
	if (data->cmds)
		free_cmds(data, cmd_nb);
	free_pid_list(data);
}
