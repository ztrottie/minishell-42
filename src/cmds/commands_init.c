/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:15:07 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/16 13:01:07 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cmds.h"

void	commands_init(t_data *data, char *line)
{
	char **command_line;
	
	data->nb_cmds = ft_word_count(line, '|');
	command_line = split_command(line);
	printf("nb_cmds:%d\n", data->nb_cmds);
}
