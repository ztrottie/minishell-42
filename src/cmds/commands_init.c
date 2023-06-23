/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:15:07 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/22 22:00:20 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cmds.h"

void	commands_init(t_data *data, char *line)
{
	data->nb_cmds = ft_word_count(line, '|');
	split_command(data, line);
}
