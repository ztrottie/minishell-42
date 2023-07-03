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

	content = ft_substr(line->line, line->i_line, len);
	if (!content)
		return (FAILURE);
	type = is_redirection(content, len);
	if (!token_add_end(tokens, type, content))
		return (ft_free(content), FAILURE);
	line->i_line += len;
	return (SUCCESS);
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
				if (!operator_control(tokens, line, operator))
					return (free_tokens(tokens), FAILURE);
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
