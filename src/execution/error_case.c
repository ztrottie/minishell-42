#include "../../include/execution.h"

static int	open_redirection_error(t_data *data, t_cmds *cmds)
{
	t_red	*ptr;

	ptr = cmds->red;
	while (ptr != NULL)
	{
		if (ptr->type == HERE_DOC)
			here_doc_main(data, &cmds->input, ptr);
		ptr = ptr->next;
	}
	return (SUCCESS);
}

int	error_redirection(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_pipe + 1)
	{
		if (open_redirection_error(data, &data->cmds[i]) <= 0)
			return (FAILURE);
		i++;
	}
	if (data->token_error)
	{
		ft_printf_fd(2, "minishell: syntax error near unexpected token `newline'\n");
		data->token_error = false;
		data->exit_code = 258;
	}
	close_all(data);
	free_all(data, false);
	return (SUCCESS);
}
