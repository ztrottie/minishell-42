#include "../../include/error.h"

int	exit_or_return(bool fork, int exit_code)
{
	if (fork)
		exit(exit_code);
	else
		return (exit_code);
}

// void	error(t_data *data)
// {
	
// }
