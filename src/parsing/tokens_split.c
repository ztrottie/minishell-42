#include "../../include/parsing.h"

void	basic_control(t_line *line, t_line *content)
{
	content->line[content->i_line] = line->line[line->i_line];
	content->i_line++;
	line->i_line++;
}

int	operator_control(t_tokens **tokens, t_line *line, int len)
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


int	variable_control(t_data *data, t_line *line, t_line *content)
{
	char 	*name;
	char 	*var_content;
	size_t	i;

	line->i_line++;
	name = variable_name(line->line + line->i_line);
	var_content = env_variable(data, name);
	if (!var_content)
		return (INVALID);
	i = 0;
	while (var_content[i])
	{
		content->line[content->i_line] = var_content[i];
		i++;
		content->i_line++;
	}
	line->i_line += ft_strlen(name);
	return (SUCCESS);
}

int	quote_control(t_data *data, t_line *line, t_line *content, int quote)
{
	line->i_line++;
	while (is_quote(line->line[line->i_line]) != quote)
	{
		if (quote == DOUBLE_QUOTE && line->line[line->i_line] == '$')
			variable_control(data, line, content);
		else
			basic_control(line, content);
	}
	line->i_line++;
	return (SUCCESS);
}

int	init_content(t_data *data, t_line *line, t_line *content)
{
	size_t	content_len;

	content_len = parsed_content_len(data, line);
	content->line = ft_calloc(content_len + 1, sizeof(char));
	if (!content->line)
		return (FAILURE);
	content->i_line = 0;
	return (SUCCESS);
}

int	string_control(t_data *data, t_tokens **tokens, t_line *line)
{
	int		quote;
	t_line	content;

	if (!init_content(data, line, &content))
		return (FAILURE);
	while (line->line[line->i_line] && !is_limitchar(line->line[line->i_line]))
	{
		quote = is_quote(line->line[line->i_line]);
		if (quote)
		{
			if (quote_control(data, line, &content, quote) == FAILURE)
				return (FAILURE);
		}
		else if (line->line[line->i_line] == '$')
		{
			if (variable_control(data, line, &content) == FAILURE)
				return (FAILURE);
		}
		else
			basic_control(line, &content);
	}
	if (!token_add_end(tokens, 0, content.line))
		return (FAILURE);
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
