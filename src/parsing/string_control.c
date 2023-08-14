/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:20:27 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:20:28 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static int	quote_control(t_data *data, t_lines *lines, int quote)
{
	lines->i_line++;
	while (lines->line[lines->i_line] && is_quote(lines->line[lines->i_line]) \
	!= quote)
	{
		if (quote == DOUBLE_QUOTE && lines->line[lines->i_line] == '$' \
		&& lines->prev_type != HERE_DOC)
		{
			if (!variable_control(data, lines, quote))
				return (FAILURE);
		}
		else
			basic_control(lines);
	}
	lines->i_line++;
	return (SUCCESS);
}

static int	init_content(t_data *data, t_lines *lines)
{
	size_t	content_len;

	content_len = parsed_content_len(data, lines);
	lines->parsed_line = ft_calloc(content_len + 1, sizeof(char));
	if (!lines->parsed_line)
		return (print_error("malloc"), FAILURE);
	lines->i_parsed_line = 0;
	lines->prev_type = 0;
	return (SUCCESS);
}

static int	token_control(t_tokens **tokens, t_lines *lines, int type)
{
	if (!token_add_end(tokens, type, lines->parsed_line))
		return (FAILURE);
	return (SUCCESS);
}

static int	string_conditions(t_data *data, t_lines *lines, int quote)
{
	if (quote)
	{
		if (quote_control(data, lines, quote) == FAILURE)
			return (ft_free(lines->parsed_line), FAILURE);
	}
	else if (lines->line[lines->i_line] == '$' && lines->prev_type != HERE_DOC)
	{
		if (variable_control(data, lines, 0) == FAILURE)
			return (ft_free(lines->parsed_line), FAILURE);
	}
	else
		basic_control(lines);
	return (SUCCESS);
}

int	string_control(t_data *data, t_tokens **tokens, t_lines *lines)
{
	int		quote;
	int		type;

	if (!init_content(data, lines))
		return (FAILURE);
	type = 0;
	while (lines->line[lines->i_line] && \
	!is_limitchar(lines->line[lines->i_line]))
	{
		quote = is_quote(lines->line[lines->i_line]);
		if (quote)
			type = QUOTES;
		string_conditions(data, lines, quote);
	}
	lines->prev_type = type;
	if (!token_control(tokens, lines, type))
		return (FAILURE);
	return (SUCCESS);
}
