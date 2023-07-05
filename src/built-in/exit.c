#include "../../include/built_in.h"

int	exit(t_data *data)
{
	ft_x2free(data->env);
	ft_printf("exit");
	return (SUCCESS, data->exit_code);
}
