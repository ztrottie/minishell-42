#include "cd.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	cd(av, &env);
	return (0);
}
