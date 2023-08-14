#include "pwd.h"

int	pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("minishell:");
		return (1);
	}
	ft_printf("%s\n", pwd);
	ft_free(pwd);
	return (SUCCESS);
}
