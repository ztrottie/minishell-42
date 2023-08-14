/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_len_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:20:11 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:20:12 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/here_doc.h"

static size_t	variable_len_control(t_data *data, t_line *line)
{
	char	*name;
	char	*exit_code;
	size_t	len;

	line->i_line++;
	name = NULL;
	len = 1;
	if (line->line[line->i_line] && line->line[line->i_line] != ' ')
	{
		name = variable_name(line->line + line->i_line);
		if (name)
			len = ft_strlen(env_variable(data, name));
		else if (line->line[line->i_line] == '?')
		{
			exit_code = ft_itoa(data->exit_code);
			if (!exit_code)
				return (0);
			len = ft_strlen(exit_code);
		}
	}
	line->i_line += ft_strlen(name);
	return (ft_free(name), len);
}

size_t	parsed_line_len(t_data *data, t_lines *lines, int type)
{
	t_line	tmp_line;
	size_t	len;

	if (cpy_line(lines, &tmp_line) <= 0)
		return (FAILURE);
	len = 0;
	while (tmp_line.line[tmp_line.i_line])
	{
		if (tmp_line.line[tmp_line.i_line] == '$' && type == 0)
			len += variable_len_control(data, &tmp_line);
		else
		{
			len++;
			tmp_line.i_line++;
		}
	}
	return (ft_free(tmp_line.line), len);
}
