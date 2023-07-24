#include "../../include/parsing.h"

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
		if (expected_token(data, ptr, start) <= 0)
			return (FAILURE);
		if (ptr->type > PIPE)
		{
			if (red_add_end(&data->cmds[cmd_nb].red, ptr->type, ptr->next->content, ptr->next->next->type) <= 0)
				return (FAILURE);
			ptr = ptr->next->next;
		}
		else if (ptr)
		{
			ft_printf("[%d]|%s|\n", ptr->type, ptr->content);
			if (ptr->type == PIPE)
				cmd_nb++;
			ptr = ptr->next;
		}
		start = false;
	}
	return (SUCCESS);
}

int	init_commands(t_data *data, t_tokens **tokens)
{
	data->cmds = ft_calloc(data->nb_pipe + 2, sizeof(t_cmds));
	if (!data->cmds)
		return (FAILURE);
	if (command_separator(data, tokens) <= 0)
		return (FAILURE);
	return (SUCCESS);
}


