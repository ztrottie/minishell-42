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

static char	**for_multiple_args(t_data *data, char **content, char **env_cpy)
{
	int	j;
	int	i;
	int	len;

	data->env_i = 0;
	j = 0;
	i = 0;
	len = ft_x2strlen(content);
	while (data->env[data->env_i] && *content)
	{
		env_cpy = ft_split(*content, ' ');
		if (ft_strncmp(env_cpy[j], content[i], len) == 0)
		{
		}
		i++;
		j++;
	}
	return (data->env);
}

static char	**reset(t_data *data, char **content, char **env_cpy)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_x2strlen(content);
	while (data->env[i] && env_cpy[j])
	{
		if (ft_strncmp(data->env[i], *content, len) > 0)
		{
			data->env[i] = ft_strdup(env_cpy[j]);
			i++;
			j++;
		}
	}
	return (data->env);
}

int	ft_unset(t_data *data, char **content)
{
	int		i;
	int		j;
	int		len;
	char	**env_cpy;

	i = 0;
	j = 1;
	len = ft_x2strlen(content);
	env_cpy = NULL;
	while (data->env[i])
	{
		if (data->env[i] != content[j])
			return (0);
		if (ft_strncmp(content[j], data->env[i], len) == 0)
		{
			env_cpy = cpy_environement(env_cpy, data->env);
			ft_x2free((void **)data->env);
			data->env = ft_calloc(len, sizeof(char));
			if (!data->env)
				return (FAILURE);
			data->env = reset(data, content, env_cpy);
			ft_x2free((void **)content);
			ft_x2free((void **)env_cpy);
		}
		i++;
		j++;
	}
	return (SUCCESS);
}

// static	char	**reset(t_data *data, char **content, char **env_cpy)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	j = 0;
// 	k = 1;
// 	while (env_cpy[j])
// 	{
// 		if (ft_strncmp(content[k], env_cpy[j], ft_x2strlen(content)))
// 		{
// 			data->env[i] = ft_strdup(env_cpy[j]);
// 			i++;
// 			k++;
// 		}
// 		j++;
// 	}
// 	return (data->env);
// }

// int	ft_unset(t_data *data, char **content)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	**env_cpy;

// 	i = 0;
// 	j = 1;
// 	env_cpy = NULL;
// 	len = ft_x2strlen(&data->env[i]);
// 	while (data->env[i] && content[j])
// 	{
	// 	if (ft_strncmp(content[j], data->env[i], ft_strlen(content[j])) == 0)
	// 		{
// 			env_cpy = cpy_environement(env_cpy, data->env);
// 			ft_x2free((void **)data->env);
// 			data->env = ft_calloc(len, sizeof(char *));
// 			if (!data->env)
// 				return (FAILURE);
// 			data->env = reset(data, &content[j], env_cpy);
// 			ft_x2free((void **)env_cpy);
// 			return (SUCCESS);
// 		}
// 		i++;
// 		j++;
// 	}
// 	return (SUCCESS);
// }
