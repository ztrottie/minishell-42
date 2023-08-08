#include "../../include/built_in.h"

int	pwd(int fd)
{	
	return (ft_printf_fd(fd, "%s\n", getcwd(NULL, 0)), 0);
}
