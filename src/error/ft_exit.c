#include "../../include/error.h"

void	ft_exit(t_data *data, char *error, char *type, bool system)
{
	(void)data;
	if (system)
	{
		perror(error);
		exit(errno);
	}
	else
	{
		dup2(STDOUT_FILENO, STDERR_FILENO);
		printf("minishell > %s '%s'", type, error);
		exit(FAILURE);
	}
}
