#include "../../include/commands.h"

static void	put_error(t_data *data, t_tokens *tokens)
{
	char *error;

	data->token_error = true;
	if (tokens)
	{
		data->token_error = false;
		error = tokens->content;
		ft_printf_fd(2, "minishell: syntax error near unexpected token `%s'\n", error);
	}
	data->exit_code = 258;
}

static int	pipe_errors(t_data *data, t_tokens *tokens, bool start)
{
	if (start == true)
		return (put_error(data, tokens), FAILURE);
	tokens = tokens->next;
	if (!tokens || tokens->type == PIPE)
		return (put_error(data, tokens), FAILURE);
	return (SUCCESS);
}

static int	red_errors(t_data *data, t_tokens *tokens)
{
	tokens = tokens->next;
	if (!tokens || tokens->type > 0)
		return (put_error(data, tokens), FAILURE);
	return (SUCCESS);
}

int	expected_token(t_data *data, t_tokens *tokens, bool start)
{
	if (tokens->type == PIPE)
		if (pipe_errors(data, tokens, start) <= 0)
			return (FAILURE);
	if (tokens->type > PIPE)
		if (red_errors(data, tokens) <= 0)
			return (FAILURE);
	return (SUCCESS);
}
