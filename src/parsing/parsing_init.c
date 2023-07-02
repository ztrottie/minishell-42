#include "../../include/parsing.h"

void	init_all(char *line_read, t_line *line, t_tokens **tokens)
{
	line->line = line_read;
	line->i_line = 0;
	*tokens = NULL;
}

int	parsing(char *line_read, t_data *data)
{
	t_line		line;
	t_tokens	*tokens;

	init_all(line_read, &line, &tokens);
	ft_printf("line_read : | %s |\n", line.line);
	if (!token_split(data, &tokens, &line))
		return (FAILURE);
	while (tokens != NULL)
	{
		ft_printf("[%d]|%s|\n", tokens->type, tokens->content);
		tokens = tokens->next;
	}
	return (SUCCESS);
}
