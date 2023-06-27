#include "../../include/env.h"

int	cpy_env(t_data *data, char **env)
{
	int	i;
	
	i = 0;
	data->env = ft_calloc(ft_x2strlen((const char **)env) + 1, sizeof(char *));
	if (!data->env)
		return (FAILURE);
	while (env[i])
	{
		data->env[i] = ft_calloc(ft_strlen(env[i]), sizeof(char));
		if (!data->env[i])
			return (FAILURE);
		data->env[i] = ft_memcpy(data->env[i], env[i], ft_strlen(env[i]));
		i++;
	}
	return (SUCCESS);
}
