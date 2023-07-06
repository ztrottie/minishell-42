#include "../../include/parsing.h"

static int	quote_control(t_data *data, t_line *line, t_line *content, int quote)
{
	line->i_line++;
	while (line->line[line->i_line] && is_quote(line->line[line->i_line]) != quote)
	{
		if (quote == DOUBLE_QUOTE && line->line[line->i_line] == '$')
		{
			if (!variable_control(data, line, content, quote))
				return (FAILURE);
		}
		else
			basic_control(line, content);
	}
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

static int	token_control(t_tokens **tokens, t_line *content, int type)
{
	if (content->line[0])
	{
		if (!token_add_end(tokens, type, content->line))
			return (FAILURE);
	}
	else
		ft_free(content->line);
	return (SUCCESS);
}

static int	string_conditions(t_data *data, t_line *line, t_line *content, int quote)
{
	if (quote)
	{
		if (quote_control(data, line, content, quote) == FAILURE)
			return (ft_free(content->line), FAILURE);
	}
	else if (line->line[line->i_line] == '$')
	{
		if (variable_control(data, line, content, 0) == FAILURE)
			return (ft_free(content->line), FAILURE);
	}
	else
		basic_control(line, content);
	return (SUCCESS);
}

int	string_control(t_data *data, t_tokens **tokens, t_line *line)
{
	int		quote;
	int		type;
	t_line	content;

	if (!init_content(data, line, &content))
		return (FAILURE);
	type = 0;
	while (line->line[line->i_line] && !is_limitchar(line->line[line->i_line]))
	{
		quote = is_quote(line->line[line->i_line]);
		if (quote)
			type = QUOTES;
		string_conditions(data, line, &content, quote);
	}
	if (!token_control(tokens, &content, type))
		return (FAILURE);
	return (SUCCESS);
}
