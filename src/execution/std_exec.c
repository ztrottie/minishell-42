/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:19:57 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:19:58 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

int	parent_process(t_data *data)
{
	if (close_all(data, true) <= 0)
		return (FAILURE);
	if (wait_pid_list(data) <= 0)
		return (FAILURE);
	return (SUCCESS);
}

int	std_exec(t_data *data)
{
	size_t	cmd_nb;
	pid_t	pid;

	cmd_nb = 0;
	sig_handler_p(true, false);
	while (cmd_nb < data->nb_pipe + 1)
	{
		if (data->cmds[cmd_nb].name && data->cmds[cmd_nb].name[0])
		{
			pid = fork();
			if (pid < 0)
				return (print_error("fork"), FAILURE);
			else if (pid == 0)
				child_process(data, cmd_nb);
			else
				if (pid_add_end(&data->pid_list, pid) <= 0)
					break ;
		}
		cmd_nb++;
	}
	if (parent_process(data) <= 0)
		return (FAILURE);
	return (SUCCESS);
}
