#include "../../include/parsing.h"

static int	operator_type(t_data *data, t_tokens **ptr, bool start, size_t *cmd_nb)
{
	if (expected_token(data, *ptr, start) <= 0)
		return (FAILURE);
	if ((*ptr)->type > PIPE)
	{
		if (red_add_end(&data->cmds[*cmd_nb].red, (*ptr)->type, (*ptr)->next->content, \
		(*ptr)->next->type) <= 0)
			return (FAILURE);
		*ptr = (*ptr)->next->next;
	}
	else
	{
		*cmd_nb += 1;
		*ptr = (*ptr)->next;
	}
	return (SUCCESS);
}

static void	content_type(t_data *data, t_tokens **ptr, size_t cmd_nb)
{
	size_t	i;

	if (!data->cmds[cmd_nb].name)
		data->cmds[cmd_nb].name = (*ptr)->content;
	i = 0;
	while (data->cmds[cmd_nb].content[i] != NULL)
		i++;
	data->cmds[cmd_nb].content[i] = (*ptr)->content;
	*ptr = (*ptr)->next;
}

static int	command_separator(t_data *data, t_tokens **tokens)
{
	t_tokens	*ptr;
	size_t		cmd_nb;
	bool		start;

	start = true;
	cmd_nb = 0;
	ptr = *tokens;
	while (ptr != NULL)
	{
		if (ptr->type >= PIPE)
		{
			if (operator_type(data, &ptr, start, &cmd_nb) <= 0)
				return (FAILURE);
		}
		else
			content_type(data, &ptr, cmd_nb);
		start = false;
	}
	return (SUCCESS);
}

int	init_commands(t_data *data, t_tokens **tokens)
{
	data->cmds = ft_calloc(data->nb_pipe + 2, sizeof(t_cmds));
	if (!data->cmds)
		return (print_error("malloc"), FAILURE);
	if (init_cmds_content(data, tokens) <= 0)
		return (FAILURE);
	if (command_separator(data, tokens) <= 0)
	{
		redirection_main(data, ERROR);
		return (free_tokens(tokens, true), FAILURE);
	}
	free_tokens(tokens, true);
	return (SUCCESS);
}


