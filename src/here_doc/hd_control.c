#include "../../include/here_doc.h"

void	hd_basic_control(t_lines *lines)
{
	lines->parsed_line[lines->i_parsed_line] = lines->line[lines->i_line];
	lines->i_line++;
	lines->i_parsed_line++;
}

int	hd_line_control(t_data *data, t_lines *lines, int type)
{
	while (lines->line[lines->i_line])
	{
		if (type == 0 && lines->line[lines->i_line] == '$')
		{
			if (hd_variable_control(data, lines) <= 0)
				return (FAILURE);
		}
		else
			hd_basic_control(lines);
	}
	return (SUCCESS);
}
