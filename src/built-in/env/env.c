#include "env.h"

static char	*var_name(char *content)
{
	int		i;
	char	*name;

	i = 0;
	while (content[i])
	{
		if (content[i] == '=')
		{
			name = ft_calloc(sizeof(char), i + 1);
			if (!name)
				return (NULL);
			ft_strlcpy(name, content, i + 1);
			return (name);
		}
		i++;
	}
	return (NULL);
}

int	print_env(char **env)
{
	int		i;
	char	*var;

	i = 0;
	var = var_name(env[i]);
	if (!var)
		return (FAILURE);
	while (env[i])
	{
		if (var != NULL)
			ft_printf("%s\n", env[i]);
		i++;
	}
	return (ft_free(var), SUCCESS);
}
