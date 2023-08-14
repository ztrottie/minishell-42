#include "export.h"

static char	**cpy_envi(char **cpy_env)
{
	int		i;
	char	**env;

	env = ft_calloc(ft_x2strlen(cpy_env) + 1, sizeof(char *));
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

int	main(int argc, char **argv, char **env)
{
	char	**cpy_env;
	int		exit_code;

	(void)argc;
	cpy_env = cpy_envi(env);
	exit_code = ft_export(argv, &env, 1);
	ft_x2free((void **)cpy_env);
	return (exit_code);
}
