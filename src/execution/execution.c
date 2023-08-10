#include "../../include/execution.h"

static int	check_builtin_nofork(t_data *data)
{
	if (ft_strcmp(data->cmds->name, "export") == 0)
		return (VALID);
	if (ft_strcmp(data->cmds->name, "unset") == 0)
		return (VALID);
	return (INVALID);
}

static int	exec_nofork(t_data *data)
{
	int	fd;

	if (data->cmds->input && data->cmds->input->fd < 0)
		return (SUCCESS);
	if (data->cmds->output)
		fd = data->cmds->output->fd;
	else
		fd = 1;
	if (ft_strcmp(data->cmds->name, "export") == 0)
		data->exit_code = ft_export(data->cmds->content, data, fd, false);
	if (ft_strcmp(data->cmds->name, "unset") == 0)
		data->exit_code = ft_unset(data->cmds->content, &data->env, false);
	return (SUCCESS);
}

int	exec_main(t_data *data)
{
	if (data->nb_pipe == 0 && check_builtin_nofork(data) == VALID)
		return (exec_nofork(data));
	return (SUCCESS);
}
