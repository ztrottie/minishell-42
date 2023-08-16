/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_nofork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:19:42 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/16 10:31:46 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/execution.h"

static int	call_exit(t_data *data)
{
	long long	tmp;
	size_t		len;
	int			i;

	len = ft_x2strlen(data->cmds->content);
	tmp = data->exit_code;
	i = 0;
	if (ft_exit(len, data->cmds->content, &tmp) <= 0)
		data->exit_code = 1;
	else
	{
		free_all(data, true);
		exit(tmp);
	}
	return (SUCCESS);
}

int	check_builtin_nofork(t_data *data)
{
	if (ft_strcmp(data->cmds->name, "export") == 0)
		return (VALID);
	if (ft_strcmp(data->cmds->name, "unset") == 0)
		return (VALID);
	if (ft_strcmp(data->cmds->name, "cd") == 0)
		return (VALID);
	if (ft_strcmp(data->cmds->name, "exit") == 0)
		return (VALID);
	return (INVALID);
}

int	exec_nofork(t_data *data)
{
	int	fd;

	if (data->cmds->input && data->cmds->input->fd < 0)
		return (SUCCESS);
	if (data->cmds->output)
		fd = data->cmds->output->fd;
	else
		fd = 1;
	sig_handler_c(false);
	if (ft_strcmp(data->cmds->name, "export") == 0)
		data->exit_code = ft_export(data->cmds->content, &data->env, fd);
	if (ft_strcmp(data->cmds->name, "unset") == 0)
		data->exit_code = ft_unset(data->cmds->content, &data->env);
	if (ft_strcmp(data->cmds->name, "cd") == 0)
		data->exit_code = cd(data->cmds->content, &data->env, data);
	if (ft_strcmp(data->cmds->name, "exit") == 0)
		call_exit(data);
	return (SUCCESS);
}
