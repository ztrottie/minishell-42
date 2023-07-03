#include "../../include/parsing.h"

void	basic_control(t_line *line, t_line *content)
{
	content->line[content->i_line] = line->line[line->i_line];
	content->i_line++;
	line->i_line++;
}

static int	operator_control(t_tokens **tokens, t_line *line, int len)
{
	char	*content;
	int		type;

	if (len)
	{
		content = ft_substr(line->line, line->i_line, len);
		type = is_redirection(content, len);
		if (!token_add_end(tokens, type, content))
			return (FAILURE);
		line->i_line += len;
		return (SUCCESS);
	}
	return (INVALID);
}

int	token_split(t_data *data, t_tokens **tokens, t_line *line)
{
	int operator;

	while (line->line[line->i_line])
	{
		if (line->line[line->i_line] != ' ')
		{
			operator = is_operator(line);
			if (operator)
			{
				if (operator_control(tokens, line, operator) == FAILURE)
					return (FAILURE);
			}
			else
				if (string_control(data, tokens, line) == FAILURE)
					return (FAILURE);
		}
		else
			line->i_line++;
	}
	return (SUCCESS);
}
