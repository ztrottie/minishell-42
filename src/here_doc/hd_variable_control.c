/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_variable_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:20:13 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:20:14 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/here_doc.h"

static int	env_varaible_control(t_data *data, t_lines *lines)
{
	char	*name;
	char	*var_content;
	size_t	i;

	name = variable_name(lines->line + lines->i_line);
	if (!name)
		return (INVALID);
	var_content = env_variable(data, name);
	if (var_content)
	{
		i = 0;
		while (var_content[i])
		{
			lines->parsed_line[lines->i_parsed_line] = var_content[i];
			lines->i_parsed_line++;
			i++;
		}
	}
	lines->i_line += ft_strlen(name);
	return (ft_free(name), SUCCESS);
}

static int	exit_variable_control(t_data *data, t_lines *lines)
{
	char	*exit_code;
	size_t	i;

	exit_code = ft_itoa(data->exit_code);
	if (!exit_code)
		return (FAILURE);
	i = 0;
	while (exit_code[i])
	{
		lines->parsed_line[lines->i_parsed_line] = exit_code[i];
		lines->i_parsed_line++;
		i++;
	}
	lines->i_line++;
	return (SUCCESS);
}

int	hd_variable_control(t_data *data, t_lines *lines)
{
	if ((lines->line[lines->i_line + 1] && \
	lines->line[lines->i_line + 1] == ' ') \
	|| is_quote(lines->line[lines->i_line + 1]) \
	|| !lines->line[lines->i_line + 1])
		return (hd_basic_control(lines), SUCCESS);
	else
		lines->i_line++;
	if (lines->line[lines->i_line] == '?')
		exit_variable_control(data, lines);
	else
		env_varaible_control(data, lines);
	return (SUCCESS);
}
