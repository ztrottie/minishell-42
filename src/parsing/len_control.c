/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:16:53 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:16:54 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static size_t	valid_name(t_data *data, char *name)
{
	char	*content;
	size_t	len;

	content = env_variable(data, name);
	len = ft_strlen(content);
	ft_free(content);
	return (len);
}

static size_t	variable_len_control(t_data *data, t_line *line)
{
	char	*name;
	char	*exit_code;
	size_t	len;

	line->i_line++;
	name = variable_name(line->line + line->i_line);
	exit_code = NULL;
	len = 1;
	if (line->line[line->i_line] && line->line[line->i_line] != ' ')
	{
		if (name)
			len = valid_name(data, name);
		else if (line->line[line->i_line] == '?')
		{
			exit_code = ft_itoa(data->exit_code);
			if (!exit_code)
				return (ft_free(name), 0);
			len = ft_strlen(exit_code);
			ft_free(exit_code);
		}
	}
	line->i_line += ft_strlen(name);
	return (ft_free(name), len);
}

static size_t	quote_len_control(t_data *data, t_line *line, int quote)
{
	size_t	len;

	len = 0;
	line->i_line++;
	while (is_quote(line->line[line->i_line]) != quote)
	{
		if (quote == DOUBLE_QUOTE && line->line[line->i_line] == '$')
			len += variable_len_control(data, line);
		else
		{
			line->i_line++;
			len++;
		}
	}
	line->i_line++;
	return (len);
}

size_t	parsed_content_len(t_data *data, t_lines *lines)
{
	t_line	tmp_line;
	size_t	len;
	int		quote;

	if (cpy_line(lines, &tmp_line) <= 0)
		return (FAILURE);
	len = 0;
	while (tmp_line.line[tmp_line.i_line] && \
	!is_limitchar(tmp_line.line[tmp_line.i_line]))
	{
		quote = is_quote(tmp_line.line[tmp_line.i_line]);
		if (quote)
			len += quote_len_control(data, &tmp_line, quote);
		else if (tmp_line.line[tmp_line.i_line] == '$')
			len += variable_len_control(data, &tmp_line);
		else
		{
			len++;
			tmp_line.i_line++;
		}
	}
	return (ft_free(tmp_line.line), len);
}
