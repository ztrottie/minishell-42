#include "../../include/built_in.h"

int	print_env(char **env, int fd)
{
	int	i;

	i = 0;
	if (!env)
		return (FAILURE);
	while (env[i])
	{
		ft_printf_fd(fd,"%s\n", env[i]);
		i++;
	}
	return (SUCCESS);
}
