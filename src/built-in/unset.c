#include "../../include/built_in.h"

int	unset(t_data *data, char *variable)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(variable);
	while (data->env[i] && variable)
	{
		if (ft_strncmp(variable, data->env[i], len) == 0)
			return (FAILURE);
	}
	return (SUCCESS);
}
