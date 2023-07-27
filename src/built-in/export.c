#include "../../include/built_in.h"

static void	export_env(t_data *data, t_export *export)
{
	int			i;
	while (export->env[i])
	{
		ft_printf("declare -x %s\n", export->env[i]);
		i++;
	}
}

static void	export_to_env(t_data *data, char **content)
{
	int				i;
	int				j;
	char	**env_cpy;

	i = 1;
	j = 0;
	env_cpy = ft_calloc(sizeof(int), ft_x2strlen(data->env) + 1);
	if (!env_cpy)
		return(FAILURE);
	env_cpy = ft_get_strjoin(env_cpy[j], content[i]);
	while (content[i])
	{
		
	}
}

int	export(t_data *data, char **content, bool fork)
{
	int	i;
	int	exit_code;

	i = 1;
	exit_code = 0;
	if (!content[1])
		export_env(data);
	else
	{
		while (content[i])
		{
			if (content[i] == '=' && (content[i][0] != '=' || content[i][0] != ft_isdigit(content[i])))
				//export in env and save the new env
				return (exit_or_return(fork, exit_code));
		}
	}
	return (exit_or_return(fork, exit_code));
}
