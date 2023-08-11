#include "exit.h"

int	main(int ac, char **av)
{
	int	exit_code;

	exit_code = 0;
	ft_exit(ac, av, exit_code);
	return (exit_code);
}
