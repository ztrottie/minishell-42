#include "../../include/built_in.h"

int	pwd(t_data *data)
{
	printf("%s\n", env_variable(data, "PWD"));
	return (SUCCESS);
}
