#include "../../include/commands.h"

static int	redirection_choice(t_tokens *tokens, t_cmds *cmds)
{
	int	type;
	int	fd;

	type = tokens->type;
	tokens = tokens->next;
	if (type == RED_IN)
	{
		fd = open(tokens->content, O_RDONLY);
		file_add_end(&cmds->input_fds, tokens->content, fd);
	}
	else if (type == RED_OUT)
	{
		fd = open(tokens->content, O_RDWR | O_CREAT | O_TRUNC, 0644);
		file_add_end(&cmds->output_fds, tokens->content, fd);
	}
	else if (type == RED_OUT_APPEND)
	{
		
	}
	tokens = tokens->next;
	return (SUCCESS);
}

int	commands_init(t_data *data, t_tokens **tokens)
{
	t_tokens	*ptr;
	int			cmds_nb;

	data->cmds = ft_calloc(data->nb_pipe + 2, sizeof(t_cmds));
	if (!data->cmds)
		return (FAILURE);
	ptr = *tokens;
	cmds_nb = 0;
	while (ptr != NULL)
	{
		if (ptr->type == PIPE)
			cmds_nb++;
		else if (ptr->type > PIPE)
			if (redirection_choice(ptr, &data->cmds[cmds_nb]) <= 0)
				return (FAILURE);
		ptr = ptr->next;
	}
	return (SUCCESS);
}
