#include "../../include/cmds.h"

void	add_quote_token(t_lines *lines, int c)
{
	lines->parsed_line[lines->i_parsed_line] = 29;
	lines->i_parsed_line++;
	lines->parsed_line[lines->i_parsed_line] = c;
	lines->i_parsed_line++;
	lines->parsed_line[lines->i_parsed_line] = 29;
	lines->i_parsed_line++;
}

void	single_quote_control(t_lines *lines)
{
	lines->i_line++;
	add_quote_token(lines, '\'');
	while (is_quote(lines->line[lines->i_line]) != SINGLE_QUOTE)
	{
		basic_control(lines);
	}
	add_quote_token(lines, '\'');
	lines->i_line++;
}


void	double_quote_control(t_data *data, t_lines *lines)
{
	lines->i_line++;
	add_quote_token(lines, '\"');
	while (is_quote(lines->line[lines->i_line]) != DOUBLE_QUOTE)
	{
		if (lines->line[lines->i_line] == '$')
			variable_control(data, lines);
		else
		{
			basic_control(lines);
		}
	}
	add_quote_token(lines, '\"');
	lines->i_line++;
}

int	find_next_quote(t_lines *line, int quote)
{
	line->i_line++;
	while (is_quote(line->line[line->i_line]) != quote && line->line[line->i_line])
		line->i_line++;
	if (line->line[line->i_line])
		return (VALID);
	return (INVALID);
}

int	check_quotes(t_lines *lines)
{
	t_lines	temp;
	int		quote;

	temp.line = lines->line;
	temp.i_line = lines->i_line;
	while (temp.line[temp.i_line])
	{
		quote = is_quote(temp.line[temp.i_line]);
		if (quote)
		{
			if (find_next_quote(&temp, quote) == INVALID)
				return (ft_putstr_fd("minishell> Invalid quotes\n", 2), INVALID);
		}
		temp.i_line++;
	}
	return (VALID);
}
