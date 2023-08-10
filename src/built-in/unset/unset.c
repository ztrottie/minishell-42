#include "unset.h"

char    **cpy_environement(char **cpy_env)
{
	int		i;
	char	**env;

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

int    ft_unset(char **content, char ***env, bool fork)
{
	int				i;
	int				j;
	int		exit_code;
	char	**env_cpy;

	i = 1;
	exit_code = 0;
	while (content[i])
	{
		if (parse_var(content[i], &exit_code))
		{
			content[i] = ft_strjoin(content[i], "=");
			j = 0;
			while (env[0][j])
			{
				if (ft_strncmp(content[i], env[0][j], ft_strlen(content[i])) == 0)
				{
					env_cpy = cpy_environement(*env);
					ft_x2free((void **)*env);
					*env = ft_calloc(ft_x2strlen(env_cpy), sizeof(char *));
					if (!env)
						return (exit_or_return(fork, exit_code));
					*env = reset(*env, content[i], env_cpy);
					ft_x2free((void **)env_cpy);
				}
				j++;
			}
			i++;
		}
	}
	*env = cpy_environement(*env);
	return (exit_or_return(fork, exit_code));
}
