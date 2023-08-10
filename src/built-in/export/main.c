#include "export.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	ft_export(argv, &env, true, 1);
}
