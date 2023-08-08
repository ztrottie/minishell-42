#include "../../include/execution.h"

static int	check_builtin_nofork(t_data *data)
{
	if (ft_strcmp(data->cmds->name, "export") == 0)
		data->exit_code = ft_export(data->cmds->content, data, data->cmds->output->fd, false);
	return (SUCCESS);
}

int	exec_main(t_data *data)
{
	if (data->nb_pipe == 0 && check_builtin_nofork(data) == VALID)
		exec_nofork(data);
}
