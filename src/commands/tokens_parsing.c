#include "../../include/parsing.h"

static void	put_error(t_data *data, t_tokens *tokens)
{
	char *error;

	if (tokens)
		error = tokens->content;
	else
		error = "newline";
	ft_printf_fd(2, "minishell: syntax error near unexpected token `%s'\n", error);
	data->exit_code = 258;
}

int	pipe_errors(t_data *data, t_tokens *tokens, int index)
{
	if (index == 0)
		return (put_error(data, tokens), FAILURE);
	tokens = tokens->next;
	if (!tokens || tokens->type == PIPE)
		return (put_error(data, tokens), FAILURE);
	return (SUCCESS);
}

int	red_errors(t_data *data, t_tokens *tokens)
{
	tokens = tokens->next;
	if (!tokens || tokens->type > 0)
		return (put_error(data, tokens), FAILURE);
	return (SUCCESS);
}

static int	expected_token(t_data *data, t_tokens *tokens, int index)
{
	if (tokens->type == PIPE)
		if (pipe_errors(data, tokens, index) <= 0)
			return (FAILURE);
	if (tokens->type > PIPE)
		if (red_errors(data, tokens) <= 0)
			return (FAILURE);
	return (SUCCESS);
}

int	tokens_parsing(t_data *data, t_tokens **tokens)
{
	t_tokens	*ptr;
	size_t		i;

	i = 0;
	ptr = *tokens;
	while (ptr != NULL)
	{
		ft_printf("[%d]|%s|\n", ptr->type, ptr->content);
		if (ptr->type >= PIPE)
		
		i++;
		ptr = ptr->next;
	}
	return (SUCCESS);
}
