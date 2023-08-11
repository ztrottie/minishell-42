#include "../../include/execution.h"

int	check_builtin_nofork(t_data *data)
{
	if (ft_strcmp(data->cmds->name, "export") == 0)
		return (VALID);
	if (ft_strcmp(data->cmds->name, "unset") == 0)
		return (VALID);
	if (ft_strcmp(data->cmds->name, "cd") == 0)
		return (VALID);
	return (INVALID);
}

int	exec_nofork(t_data *data)
{
	int	fd;

	if (data->cmds->input && data->cmds->input->fd < 0)
		return (SUCCESS);
	if (data->cmds->output)
		fd = data->cmds->output->fd;
	else
		fd = 1;
	if (ft_strcmp(data->cmds->name, "export") == 0)
		data->exit_code = ft_export(data->cmds->content, &data->env, false, fd);
	if (ft_strcmp(data->cmds->name, "unset") == 0)
		data->exit_code = ft_unset(data->cmds->content, &data->env, false);
	if (ft_strcmp(data->cmds->name, "cd") == 0)
		data->exit_code = cd(data->cmds->content, &data->env);
	return (SUCCESS);
}
