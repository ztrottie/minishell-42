#include "pwd.h"

int	pwd(void)
{
	if (getcwd(NULL, 0) == NULL)
		return (FAILURE);
	ft_printf("%s\n", getcwd(NULL, 0));
	return (SUCCESS);
}
