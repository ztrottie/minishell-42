#include "../../include/built_in.h"

static char	**cpy_environement(char **env, char **cpy_env)
{
	int	i;

	i = 0;
	env = ft_calloc(ft_x2strlen(cpy_env) + 1, sizeof(char *));
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

int	check_valid_args(char **content)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (content[i])
	{
		j = 0;
		while (content[i][j])
		{
			if (!is_valid_var(content[i][j]))
				return (INVALID);
			j++;
		}
		i++;
	}
	return (VALID);
}

int	ft_unset(t_data *data, char **content)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (content[i])
	{
		while (content[i][j])
		{
			if (check_valid_args(content) > 0)
				return (FAILURE);
			if (ft_strncmp(content[i], data->env, ft_x2strlen(content)))
			{
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}


// int	ft_unset(t_data *data, char **content)
// {
// 	int		i;
// 	int		j;
// 	char	**env_cpy;

// 	i = 0;
// 	env_cpy = NULL;
// 	if (!check_valid_args(content))
// 		return (0);
// 	while (data->env[i] && content)
// 	{
// 		if (ft_strncmp(content, data->env[i], ft_strlen(content)) == 0)
// 		{
// 			env_cpy = cpy_environement(env_cpy, data->env);
// 			ft_x2free((void **)data->env);
// 			data->env = ft_calloc(ft_x2strlen(content), sizeof(char *));
// 			if (!data->env)
// 				return (FAILURE);
// 			data->env = reset(data, content, env_cpy);
// 			ft_x2free((void **)env_cpy);
// 			return (SUCCESS);
// 		}
// 		i++;
// 	}
// 	return (SUCCESS);
// }
