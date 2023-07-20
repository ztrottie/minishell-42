#include "../../include/parsing.h"

void	basic_control(t_lines *lines)
{
	lines->parsed_line[lines->i_parsed_line] = lines->line[lines->i_line];
	lines->i_parsed_line++;
	lines->i_line++;
}

static int	operator_control(t_tokens **tokens, t_lines *lines, int len)
{
	char	*content;
	int		type;

	content = ft_substr(lines->line, lines->i_line, len);
	if (!content)
		return (FAILURE);
	type = is_redirection(content, len);
	lines->prev_type = type;
	if (!token_add_end(tokens, type, content))
		return (ft_free(content), FAILURE);
	lines->i_line += len;
	return (SUCCESS);
}

int	token_split(t_data *data, t_tokens **tokens, t_lines *lines)
{
	int operator;

	while (lines->line[lines->i_line])
	{
		if (lines->line[lines->i_line] != ' ')
		{
			operator = is_operator(lines);
			if (operator)
			{
				if (!operator_control(tokens, lines, operator))
					return (free_tokens(tokens), FAILURE);
			}
			else
				if (string_control(data, tokens, lines) == FAILURE)
					return (FAILURE);
		}
		else
			lines->i_line++;
	}
	return (SUCCESS);
}
