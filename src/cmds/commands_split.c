/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:45:13 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/21 14:59:43 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cmds.h"

void	operator_control(t_lines *lines, int operator)
{
	while (operator > 0)
	{
		lines->parsed_line[lines->i_parsed_line] = lines->line[lines->i_line];
		lines->i_parsed_line++;
		lines->i_line++;
		operator--;
	}
	lines->parsed_line[lines->i_parsed_line] = 29;
	lines->i_parsed_line++;
}

void	space_control(t_lines *lines)
{
	if (lines->parsed_line[lines->i_parsed_line - 1] != 29)
	{
		lines->parsed_line[lines->i_parsed_line] = 29;
		lines->i_parsed_line++;
	}
	lines->i_line++;
}

void	quotes_control(t_lines *lines, int quote)
{
	if (quote == SINGLE_QUOTE)
		single_quote_control(lines);
}

void	parse_command(t_lines *lines)
{
	int	operator;
	int	quote;
	size_t	len;
	
	len = ft_strlen(lines->line);
	while (lines->line[lines->i_line])
	{
		operator = is_operator(lines->line, lines->i_line);
		quote = is_quote(lines->line[lines->i_line]);
		if (operator > 0)
			operator_control(lines, operator);
		else if (ft_isspace(lines->line[lines->i_line]))
			space_control(lines);
		else if (quote > 0)
			quotes_control(lines, quote);
		else
		{
			lines->parsed_line[lines->i_parsed_line] = lines->line[lines->i_line];
			lines->i_parsed_line++;
			lines->i_line++;
		}
	}
}

char **split_command(char *line_read)
{
	int		len;
	t_lines	lines;
	char	**parse_line;
	size_t	word;
	
	ft_bzero(&lines, sizeof(t_lines));
	lines.line = line_read;
	len = ft_strlen(line_read) + nb_metachar(line_read) * 2;
	lines.parsed_line = ft_calloc(len, sizeof(char *));
	parse_command(&lines);
	ft_printf("%s\n", lines.parsed_line);
	parse_line = ft_split(lines.parsed_line, 29);
	word = ft_word_count(lines.parsed_line, 29);
	for (size_t i = 0; i < word; i++)
		ft_printf("|%s|\n", parse_line[i]);
	return (NULL);
}
