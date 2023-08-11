#include "export.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	return (ft_export(argv, &env, true, 1));
}
