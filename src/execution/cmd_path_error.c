#include "../../include/execution.h"

void	path_error(t_data *data, int cmd_nb, int type)
{
	ft_printf_fd(2, "minishell: ");
	if (type == EACCES)
	{
		perror(data->cmds[cmd_nb].name);
		exit(126);
	}
	else
	{
		if (type == COMMAND_NOT_FOUND)
			ft_printf_fd(2, "%s: command not found\n", data->cmds[cmd_nb].name);
		else
			perror(data->cmds[cmd_nb].name);
		exit(127);
	}
}
