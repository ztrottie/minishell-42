#include "../../include/parsing.h"

static size_t	variable_len_control(t_data *data, t_line *line)
{
	char	*name;
	size_t	len;

	line->i_line++;
	len = 0;
	if (line->line[line->i_line])
	{
		name = variable_name(line->line + line->i_line);
		ft_printf("%s\n", name);
		len = ft_strlen(env_variable(data, name));
	}
	line->i_line += ft_strlen(name);
	return (len);
}

static size_t	quote_len_control(t_data *data, t_line *line, int quote)
{
	size_t	len;

	len = 0;
	line->i_line++;
	while (is_quote(line->line[line->i_line]) != quote)
	{
		if (quote == DOUBLE_QUOTE && line->line[line->i_line] == '$')
			len += variable_len_control(data, line);
		else
		{
			line->i_line++;
			len++;
		}
	}
	line->i_line++;
	return (len);
}

size_t	parsed_content_len(t_data *data, t_line *line)
{
	t_line	tmp_line;
	size_t	len;
	int		quote;

	cpy_line(line, &tmp_line);
	len = 0;
	while (tmp_line.line[tmp_line.i_line] && \
	!is_limitchar(tmp_line.line[tmp_line.i_line]))
	{
		quote = is_quote(tmp_line.line[tmp_line.i_line]);
		if (quote)
			len += quote_len_control(data, &tmp_line, quote);
		else if (tmp_line.line[tmp_line.i_line] == '$')
			len += variable_len_control(data, &tmp_line);
		else
		{
			len++;
			tmp_line.i_line++;
		}
	}
	return (len);
}
