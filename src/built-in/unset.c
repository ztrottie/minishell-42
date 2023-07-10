#include "../../include/built_in.h"

char    **cpy_environement(char **env, char **cpy_env)
{
	int   i;

	i = 0;
	while (cpy_env[i])
		i++;
	env = ft_calloc(i + 1, sizeof(char *));
	if (!env)
		return (NULL);
	i = 0;
	while (cpy_env[i])
	{
		env[i] = ft_strdup(cpy_env[i]);
		i++;
	}
	return (env);
}

// static int    is_valid_args(char **content)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (content[i])
// 	{
// 		j = 0;
// 		while (content[i][j])
// 		{
// 			if (!is_valid_var(content[i][j]))
// 				return (FAILURE);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (SUCCESS);
// }

static char    **reset(char **env, char *variable, char **env_cpy)
	{
	int    i;
	int    j;

	i = 0;
	j = 0;
	while (env_cpy[j])
	{
		if (ft_strncmp(variable, env_cpy[j], ft_strlen(variable)))
		{
			env[i] = ft_strdup(env_cpy[j]);
			i++;
		}
		j++;
	}
	return (env);
}

int    ft_unset(t_data *data, char **content)
{
	int		i;
	int		j;
	char	**env_cpy;
	char	**env;

	i = 1;
	env = data->env;
	while (content[i])
	{
		content[i] = ft_strjoin(content[i], "=");
		j = 0;
		while (env[j])
		{
			if (ft_strncmp(content[i], env[j], ft_strlen(content[i])) == 0)
			{
				env_cpy = cpy_environement(NULL, env);
				ft_x2free((void **)env);
				env = ft_calloc(ft_x2strlen(env_cpy), sizeof(char *));
				printf("non\n");
				if (!env)
					return (FAILURE);
				env = reset(env, content[i], env_cpy);
				ft_x2free((void **)env_cpy);
			}
			j++;
		}
		i++;
	}
	data->env = cpy_environement(NULL, env);
	ft_x2free((void **)env);
	return (SUCCESS);
}
