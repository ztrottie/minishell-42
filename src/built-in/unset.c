#include "../../include/built_in.h"

static char	**cpy_environement(char **env, char **cpy_env)
{
	int	i;

	i = 0;
	env = ft_calloc(ft_x2strlen((const char **)cpy_env) + 1, sizeof(char *));
	if (!env)
		return (NULL);
	while (cpy_env[i])
	{
		env[i] = ft_strdup(cpy_env[i]);
		i++;
	}
	return (env);
}

static	char	**reset(t_data *data, char *variable, char **env_cpy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env_cpy[j])
	{
		if (ft_strncmp(variable, env_cpy[j], ft_strlen(variable)))
		{
			data->env[i] = ft_strdup(env_cpy[j]);
			i++;
		}
		j++;
	}
	return (data->env);
}

int	ft_unset(t_data *data, char *variable)
{
	int		i;
	int		len;
	char	**env_cpy;

	i = 0;
	env_cpy = NULL;
	len = ft_x2strlen((const char **)data->env[i]);
	while (data->env[i] && variable)
	{
		if (ft_strncmp(variable, data->env[i], ft_strlen(variable)) == 0)
		{
			env_cpy = cpy_environement(env_cpy, data->env);
			ft_x2free((void **)data->env);
			data->env = ft_calloc(len, sizeof(char *));
			if (!data->env)
				return (FAILURE);
			data->env = reset(data, variable, env_cpy);
			ft_x2free((void **)env_cpy);
			return (SUCCESS);
		}
		i++;
	}
	return (SUCCESS);
}
