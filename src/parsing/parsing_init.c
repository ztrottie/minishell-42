#include "../../include/parsing.h"

static void	init_parsing(t_data *data, char *line_read, t_lines *lines, t_tokens **tokens)
{
	data->nb_pipe = 0;
	lines->line = line_read;
	lines->i_line = 0;
	*tokens = NULL;
}

static int	find_next_quote(t_line *line, int quote)
{
	line->i_line++;
	while (is_quote(line->line[line->i_line]) != quote && line->line[line->i_line])
		line->i_line++;
	if (line->line[line->i_line])
		return (VALID);
	return (INVALID);
}

static int	check_quotes(char *line_read)
{
	t_line	temp;
	int		quote;

	temp.line = line_read;
	temp.i_line = 0;
	while (temp.line[temp.i_line])
	{
		quote = is_quote(temp.line[temp.i_line]);
		if (quote)
		{
			if (find_next_quote(&temp, quote) == INVALID)
				return (ft_putstr_fd("minishell: Invalid quotes\n", 2), INVALID);
		}
		temp.i_line++;
	}
	return (VALID);
}

int	parsing(char *line_read, t_data *data)
{
	t_lines		lines;
	t_tokens	*tokens;

	if (check_quotes(line_read) <= 0)
		return (FAILURE);
	init_parsing(data, line_read, &lines, &tokens);
	if (token_split(data, &tokens, &lines) <= 0)
		return (FAILURE);
	if (tokens_parsing(data, &tokens) <= 0)
		return (FAILURE);
	if (commands_separator(data, &tokens) <= 0)
		return (FAILURE);
	return (SUCCESS);
}
