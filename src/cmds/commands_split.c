#include "../../include/cmds.h"

void	operator_control(t_lines *lines, int operator)
{
	if (lines->line[lines->i_line - 1] && \
	lines->parsed_line[lines->i_parsed_line - 1] != 29)
	{
		lines->parsed_line[lines->i_parsed_line] = 29;
		lines->i_parsed_line++;
	}
	while (operator > 0)
	{
		basic_control(lines);
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

void	quotes_control(t_data *data, t_lines *lines, int quote)
{
	if (quote == SINGLE_QUOTE)
		single_quote_control(lines);
	if (quote == DOUBLE_QUOTE)
		double_quote_control(data, lines);
}

void	variable_control(t_data *data, t_lines *lines)
{
	char	*var_name;
	char	*var_content;
	size_t	i;

	lines->i_line++;
	var_name = variable_name(lines->line + lines->i_line);
	var_content = env_variable(data, var_name);
	if (!var_content)
	{
		ft_free(var_name);
		lines->i_line += variable_name_len(lines->line + lines->i_line);
		return ;
	}
	i = 0;
	while (var_content[i])
	{
		lines->parsed_line[lines->i_parsed_line] = var_content[i];
		lines->i_parsed_line++;
		i++;
	}
	lines->i_line += variable_name_len(lines->line + lines->i_line);
}

void	split_command(t_data *data, t_lines *lines)
{
	int	operator;
	int	quote;

	while (lines->line[lines->i_line])
	{
		operator = is_operator(lines->line, lines->i_line);
		quote = is_quote(lines->line[lines->i_line]);
		if (operator > 0)
			operator_control(lines, operator);
		else if (ft_isspace(lines->line[lines->i_line]))
			space_control(lines);
		else if (quote > 0)
			quotes_control(data, lines, quote);
		else if (lines->line[lines->i_line] == '$')
			variable_control(data, lines);
		else
			basic_control(lines);
	}
}
