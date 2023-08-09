#include "../../include/execution.h"

int	child_process(t_data *data, int cmd_nb)
{
	
}

int	std_exec(t_data *data)
{
	int		cmd_nb;
	pid_t	pid;

	cmd_nb = 0;
	while (cmd_nb < data->nb_pipe + 1)
	{
		pid = fork();
		if (pid < 0)
		{
			return (FAILURE);
		}
		else if (pid == 0)
		{
			child_process(data, cmd_nb);
		}
		else
			if (pid_add_end(&data->pid, pid))
				break ;
		cmd_nb++;
	}
	return (SUCESS);
}
