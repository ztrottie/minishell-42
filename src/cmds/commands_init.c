/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:15:07 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/14 16:53:15 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cmds.h"

void	open_pipes(t_data *data)
{
	int	i;

	data->pipe = ft_calloc(data->nb_cmds - 1, sizeof(int *));
	i = 0;
	while (i < data->nb_cmds - 1)
	{
		data->pipe[i] = ft_calloc(2, sizeof(int));
		pipe(data->pipe[i]);
		i++;
	}
}

void	open_fds(t_data *data, char *line)
{
	data->input_fds = ft_calloc(ft_word_count(line, '<'));
}

void	commands_init(t_data *data, char *line)
{
	data->nb_cmds = ft_word_count(line, '|');
	open_pipes(data);
	open_fds(data, line);
	ft_printf("%s %d\n", line, data->nb_cmds);
}
