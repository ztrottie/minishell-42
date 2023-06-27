#include "../../include/built_in.h"

int	print_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (FAILURE);
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (SUCCESS);
}
