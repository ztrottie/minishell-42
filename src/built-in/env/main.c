#include "env.h"

int	main(int ac, char **av, char **env)
{
	(void) av;
	if (ac != 1)
		return (1);
	print_env(env);
}
