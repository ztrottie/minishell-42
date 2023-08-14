#include "export.h"

static int	dup_env(char ***new_env, char ***env)
{
	int	i;

	i = 0;
	while (env[0][i])
	{
		new_env[0][i] = ft_strdup(env[0][i]);
		if (!new_env[0][i])
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int	init_add_var(char *content, char ***new_env, int len)
{
	bool	trigger;
	int		var_len;
	int		content_i;
	int		new_env_i;

	var_len = ft_strlen(content);
	new_env[0][len] = ft_calloc(len, sizeof(char));
	if (!new_env[0][len])
		return (FAILURE);
	content_i = 0;
	new_env_i = 0;
	trigger = false;
	while (content[content_i])
	{
		if (content[content_i] == '+' && trigger == false)
			trigger = true;
		else
		{
			new_env[0][len][new_env_i] = content[content_i];
			new_env_i++;
		}
		content_i++;
	}
	return (SUCCESS);
}

static int	init_var(char *content, char ***new_env, int len, int type)
{
	if (type == ADD)
	{
		if (init_add_var(content, new_env, len) <= 0)
			return (FAILURE);
	}
	else
	{
		new_env[0][len] = ft_strdup(content);
		if (!new_env[0][len])
			return (FAILURE);
	}
	return (SUCCESS);
}

int	create_var(char *content, char ***env, int type)
{
	int		len;
	char	**new_env;

	len = ft_x2strlen(*env);
	new_env = ft_calloc(len + 2, sizeof(char *));
	if (dup_env(&new_env, env) <= 0)
		return (FAILURE);
	if (init_var(content, &new_env, len, type) <= 0)
		return (FAILURE);
	env[0] = new_env;
	ft_x2free((void **)new_env);
	return (SUCCESS);
}
