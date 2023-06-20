/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:45:13 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/20 03:33:24 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cmds.h"

void	parse_command(t_lines *lines)
{
	while (lines->line[lines->i_line])
	{
		lines->parsed_line[lines->i_parsed_line] = lines->line[lines->i_line];
		lines->i_parsed_line++;
		lines->i_line++;
	}
}

char **split_command(char *line_read)
{
	int		len;
	t_lines	lines;
	
	ft_bzero(&lines, sizeof(t_lines));
	lines.line = line_read;
	len = ft_strlen(line_read) + nb_metachar(line_read) * 3;
	lines.parsed_line = ft_calloc(len, sizeof(char *));
	parse_command(&lines);
	printf("%s %d\n", lines.parsed_line, len);
	return (NULL);
}
