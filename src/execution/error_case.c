#include "../../include/execution.h"

static int	open_redirection_error(t_data *data, t_cmds *cmds)
{
	t_red	*ptr;
	int		exit_code;

	ptr = cmds->red;
	while (ptr != NULL)
	{
		if (ptr->type == HERE_DOC)
		{
			exit_code = here_doc_main(data, ptr, NULL, true);
			if (exit_code == FAILURE)
				return (FAILURE);
			else if (exit_code == INVALID)
				return (INVALID);
			if (close_all(data) <= 0)
				return (FAILURE);
		}
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
		if (open_redirection_error(data, &data->cmds[i]) < 0)
			return (FAILURE);
		i++;
	}
	if (data->token_error)
	{
		ft_printf_fd(2, "minishell: syntax error near unexpected token `newline'\n");
		data->token_error = false;
		data->exit_code = 258;
	}
	if (close_all(data) <= 0)
		return (FAILURE);
	free_all(data, false);
	return (SUCCESS);
}
