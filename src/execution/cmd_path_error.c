#include "../../include/execution.h"

void	exit_child(t_data *data, int exit_code)
{
	ft_printf("ayo");
	free_all(data, true);
	exit(exit_code);
}

void	path_error(t_data *data, int cmd_nb, int type, char **splited_path)
{
	ft_x2free((void **)splited_path);
	ft_printf_fd(2, "minishell: ");
	if (type == EACCES)
	{
		perror(data->cmds[cmd_nb].name);
		exit_child(data, 126);
	}
	else
	{
		if (type == COMMAND_NOT_FOUND)
			ft_printf_fd(2, "%s: command not found\n", data->cmds[cmd_nb].name);
		else
			perror(data->cmds[cmd_nb].name);
		exit_child(data, 127);
	}
}
