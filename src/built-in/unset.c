#include "../../include/built_in.h"

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

int	ft_strsearch(char *str, char reject)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == reject) && str[i])
			return (i);
		i++;
	}
	return (0);
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

static void	check_export(char *var, char **env_cpy, t_export *export)
{
	int	j;

	j = 0;
	while (export && export->env[j])
	{
		if (ft_strncmp(var, export->env[j], ft_strlen(var + 1)) == 0)
		{
			env_cpy = cpy_environement(export->env);
			ft_x2free((void **)export->env);
			export->env = ft_calloc(ft_x2strlen(env_cpy), sizeof(char *));
			export->env = reset(export->env, var, env_cpy);
			ft_x2free((void **)env_cpy);
			j--;
		}
		j++;
	}
}

int    ft_unset(t_data *data, char **content, t_export *export , bool fork)
{
	int				i;
	int				j;
	int		exit_code;
	char	**env_cpy;
	char	**env;

	i = 1;
	exit_code = 0;
	env = data->env;
	while (content[i])
	{
		if (ft_strsearch(content[i], 32))
		{
			ft_printf_fd(2, "minishell: unset: `%s : not a valid identifier\n", content[i]);
			exit_code = 1;
			i++;
			continue ;
		}
		check_export(ft_strdup(content[i]), env_cpy, export);
		content[i] = ft_strjoin(content[i], "=");
		j = 0;
		while (env[j])
		{
			if (ft_strncmp(content[i], env[j], ft_strlen(content[i])) == 0)
			{
				env_cpy = cpy_environement(env);
				ft_x2free((void **)env);
				env = ft_calloc(ft_x2strlen(env_cpy), sizeof(char *));
				if (!env)
					return (exit_or_return(fork, exit_code));
				env = reset(env, content[i], env_cpy);
				ft_x2free((void **)env_cpy);
				j--;
			}
			j++;
		}
		i++;
	}
	data->env = cpy_environement(env);
	ft_x2free((void **)env);
	return (exit_or_return(fork, exit_code));
}
