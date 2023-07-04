#include "../../include/parsing.h"

static void	init_parsing(t_data *data, char *line_read, t_line *line, t_tokens **tokens)
{
	data->nb_pipe = 0;
	line->line = line_read;
	line->i_line = 0;
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
	t_line		line;
	t_tokens	*tokens;

	init_parsing(data, line_read, &line, &tokens);
	if (check_quotes(line_read) <= 0)
		return (FAILURE);
	if (token_split(data, &tokens, &line) <= 0)
		return (FAILURE);
	if (tokens_parsing(data, &tokens) <= 0)
		return (FAILURE);
	while (tokens != NULL)
	{
		ft_printf("[%d]|%s|\n", tokens->type, tokens->content);
		tokens = tokens->next;
	}
	// if (cmds_init(data, &tokens) <= 0)
	// 	return (FAILURE);
	return (SUCCESS);
}
