#include "../../include/built_in.h"

static void	export_env(t_data *data)
{
	char	**env;
	int			i;

	data->env = env;
	while (env[i])
	{
		ft_printf("declare -x %s\n", env[i]);
		i++;
	}
}

static void	export_to_env(t_data *data, char **content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		
	}
}

int	export(t_data *data, char **content)
{
	int	i;
	int	exit_code;

	i = 1;
	exit_code = 0;
	if (!content[1])
		export_env(data);
	else
	{
		if (content[i] == '=' && (content[i][0] != '=' || content[i][0] != ft_isdigit(content[i])))
			//export in env and save the new env
			return (exit_or_return(fork, exit_code));
	}
	return (SUCCESS);
}
