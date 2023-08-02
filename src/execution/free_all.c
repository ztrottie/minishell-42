#include "../../include/execution.h"

static void	free_cmds(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_pipe + 1)
	{
		data->cmds[i].content = ft_x2free((void **)data->cmds[i].content);
		free_red_list(&data->cmds[i].red);
		free_files(&data->cmds[i].input);
		free_files(&data->cmds[i].output);
		i++;
	}
	data->cmds = ft_free(data->cmds);
}

void	free_all(t_data *data, bool all)
{
	if (data->cmds)
		free_cmds(data);
	free_pid_list(data);
	if (all)
		ft_x2free((void **)data->env);
}