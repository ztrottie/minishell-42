#include "../../include/execution.h"

int	exec_main(t_data *data)
{
	if (data->nb_pipe == 0 && data->cmds->name && check_builtin_nofork(data) == VALID)
		return (exec_nofork(data));
	else
		if (std_exec(data) <= 0)
			return (FAILURE);
	return (SUCCESS);
}
