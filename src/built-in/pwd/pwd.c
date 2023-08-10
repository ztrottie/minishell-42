#include "pwd.h"

int	pwd()
{	
	if (getcwd(NULL, 0) == NULL)
		return (FAILURE);
	ft_printf("%s\n", getcwd(NULL, 0));
}
