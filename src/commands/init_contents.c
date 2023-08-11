#include "../../include/commands.h"

static void	red_type(t_tokens **ptr)
{
	if (!(*ptr)->next || (*ptr)->next->type >= PIPE)
		*ptr = (*ptr)->next;
	else
		*ptr = (*ptr)->next->next;
}

static int	init_content(t_data *data, t_tokens **ptr, \
size_t *cmd_nb, size_t *content_count)
{
	data->cmds[*cmd_nb].content = ft_calloc(*content_count + 1, sizeof(char *));
	if (!data->cmds[*cmd_nb].content)
		return (print_error("malloc"), FAILURE);
	*cmd_nb += 1;
	*content_count = 0;
	if (*ptr)
		*ptr = (*ptr)->next;
	return (SUCCESS);
}

static void	basic_operation(t_tokens **ptr, size_t *content_count)
{
	*ptr = (*ptr)->next;
	*content_count += 1;
}

int	init_cmds_content(t_data *data, t_tokens **tokens)
{
	t_tokens	*ptr;
	size_t		cmd_nb;
	size_t		content_count;

	cmd_nb = 0;
	content_count = 0;
	ptr = *tokens;
	while (ptr != NULL)
	{
		if (ptr->type > PIPE)
			red_type(&ptr);
		else if (ptr->type == PIPE)
		{
			if (init_content(data, &ptr, &cmd_nb, &content_count) <= 0)
				return (FAILURE);
		}
		else
			basic_operation(&ptr, &content_count);
	}
	if (init_content(data, &ptr, &cmd_nb, &content_count) <= 0)
		return (FAILURE);
	return (SUCCESS);
}
