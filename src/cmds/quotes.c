#include "../../include/cmds.h"

void	single_quote_control(t_lines *lines)
{
	lines->i_line++;
	while (is_quote(lines->line[lines->i_line]) != SINGLE_QUOTE)
	{
		basic_control(lines);
	}
	lines->i_line++;
}


void	double_quote_control(t_data *data, t_lines *lines)
{
	lines->i_line++;
	while (is_quote(lines->line[lines->i_line]) != DOUBLE_QUOTE)
	{
		if (lines->line[lines->i_line] == '$')
			variable_control(data, lines);
		else
		{
			basic_control(lines);
		}
	}
	lines->i_line++;
}