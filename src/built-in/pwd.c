#include "../../include/built_in.h"

int	pwd(void)
{
	char	*cwd;

	cwd = NULL;
	return (printf("%s\n", getcwd(cwd, sizeof(cwd))), SUCCESS);
}
