#include "unset.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	ft_unset(av, &env);
	return (0);
}
