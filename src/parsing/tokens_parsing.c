#include "../../include/parsing.h"

static void	put_error(t_data *data, char *error)
{
	ft_printf_fd(2, "minishell: syntax error near unexpected token `%s'\n", error);
	data->exit_code = 258;
}

static int	expected_token(t_data *data, t_tokens *tokens, int expected, int except)
{
	tokens = tokens->next;
	if (tokens == NULL)
		return (put_error(data, "newline"), INVALID);
	if (tokens->type > expected || tokens->type == except)
		return (put_error(data, tokens->content), INVALID);
	return (SUCCESS);
}

static int redirection_init(t_data *data, t_tokens *tokens)
{
	if (expected_token(data, tokens, 0, -1) <= 0)
		return (INVALID);
	return (SUCCESS);
}

int	tokens_parsing(t_data *data, t_tokens **tokens)
{
	t_tokens	*ptr;

	ptr = *tokens;
	while (ptr != NULL)
	{
		if (ptr->type > 1)
			if (redirection_init(data, ptr) <= 0)
				return (INVALID);
		if (ptr->type == 1)
		{
			data->nb_pipe++;
			if (!expected_token(data, ptr, 5, 1))
				return (INVALID);
		}
		ptr = ptr->next;
	}
	return (SUCCESS);
}
