#include "unset.h"

char	**cpy_environement(char **cpy_env)
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

static char	**reset(char **env, char *variable, char **env_cpy)
	{
	int	i;
	int	j;

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

static void	unset_var(char **content, char ***env, int i, int j)
{
	char	**env_cpy;

	while (env[0][j])
	{
		if (ft_strncmp(content[i], env[0][j], ft_strlen(content[i])) == 0)
		{
			env_cpy = cpy_environement(*env);
			ft_x2free((void **)*env);
			*env = ft_calloc(ft_x2strlen(env_cpy), sizeof(char *));
			*env = reset(*env, content[i], env_cpy);
			ft_x2free((void **)env_cpy);
			j--;
		}
		j++;
	}
	ft_x2free((void **)*env);
}

int	ft_unset(char **content, char ***env, bool fork)
{
	int	i;
	int	j;
	int	exit_code;

	i = 1;
	exit_code = 0;
	while (content[i])
	{
		if (parse_var(content[i], &exit_code))
		{
			j = 0;
			unset_var(content, env, i, j);
			i++;
		}
	}
	*env = cpy_environement(*env);
	return (exit_or_reset(fork, exit_code));
}
