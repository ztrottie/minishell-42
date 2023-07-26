#include "../../include/built_in.h"

static int	add_to_env(char **content)
{
	int	i;

	i = 0;

}

static void	check_args(char **content)
{
	int	i;

	i = 0;

}

int	export(t_data *data, char **content)
{
	int	i;

	i = 1;
	if (!content[1])
		ft_printf("declare -x %s", content[i]);
	else
	{
	}
	return (SUCCESS);
}
