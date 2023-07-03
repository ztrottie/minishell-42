#include "../../include/parsing.h"

static int	variable_control(t_data *data, t_line *line, t_line *content)
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

static int	quote_control(t_data *data, t_line *line, t_line *content, int quote)
{
	line->i_line++;
	while (line->line[line->i_line] && is_quote(line->line[line->i_line]) != quote)
	{
		if (quote == DOUBLE_QUOTE && line->line[line->i_line] == '$')
			variable_control(data, line, content);
		else
			basic_control(line, content);
	}
	if (!line->line[line->i_line])
		return (FAILURE);
	line->i_line++;
	return (SUCCESS);
}

static int	init_content(t_data *data, t_line *line, t_line *content)
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
