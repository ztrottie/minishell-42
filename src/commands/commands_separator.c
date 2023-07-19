#include "../../include/commands.h"

static int	redirection_choice(t_data *data, t_tokens **tokens, t_cmds *cmds)
{
	int			type;
	int			fd;

	type = (*tokens)->type;
	*tokens = (*tokens)->next;
	if (type == RED_IN)
	{
		fd = open((*tokens)->content, O_RDONLY);
		if (file_add_end(&cmds->input_fds, (*tokens)->content, fd) <= 0)
			return (FAILURE);
	}
	else if (type == HERE_DOC)
	{
		if (here_doc_main(data, &cmds->input_fds, (*tokens)->content, (*tokens)->type) <= 0)
			return (FAILURE);
	}
	else if (type == RED_OUT)
		fd = open((*tokens)->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == RED_OUT_APPEND)
		fd = open((*tokens)->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (type == RED_OUT || type == RED_OUT_APPEND)
		if (file_add_end(&cmds->output_fds, (*tokens)->content, fd) <= 0)
			return (FAILURE);
	*tokens = (*tokens)->next;
	return (SUCCESS);
}

static int commands_init(t_data *data)
{
	data->cmds = ft_calloc(data->nb_pipe + 2, sizeof(t_cmds));
	if (!data->cmds)
		return (FAILURE);
	return (SUCCESS);
}

size_t	content_size(t_tokens **tokens)
{
	t_tokens	*ptr;
	size_t		count;

	ptr = *tokens;
	count = 0;
	while (ptr != NULL && ptr->type != PIPE)
	{
		if (ptr->type > PIPE)
			ptr = ptr->next;
		else
			count++;
		ptr = ptr->next;
	}
	return (count);
}

int	init_content(t_data *data, t_tokens **tokens, int cmds_nb)
{
	size_t	len;

	if ((*tokens)->type == PIPE)
		*tokens = (*tokens)->next;
	len = content_size(tokens);
	data->cmds[cmds_nb].content = ft_calloc(len + 1, sizeof(char *));
	if (!data->cmds[cmds_nb].content)
		return (FAILURE);
	return (SUCCESS);
}

int	commands_separator(t_data *data, t_tokens **tokens)
{
	t_tokens	*ptr;
	int			cmds_nb;

	if (commands_init(data) <= 0)
		return (FAILURE);
	ptr = *tokens;
	cmds_nb = -1;
	while (ptr != NULL)
	{
		if (ptr->type == PIPE || (ptr == *tokens && cmds_nb < 0))
		{
			cmds_nb++;
			if (init_content(data, &ptr, cmds_nb) <= 0)
				return (FAILURE);
		}
		else if (ptr->type > PIPE)
		{
			if (redirection_choice(data, &ptr, &data->cmds[cmds_nb]) <= 0)
				return (FAILURE);
		}
		else
			ptr = ptr->next;
	}
	wait_pid_list(&data->pid);
	return (SUCCESS);
}
