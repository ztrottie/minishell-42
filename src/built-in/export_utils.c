#include "../../include/built_in.h"

void	check_if_exist(t_export *export, char *var)
{
	int	i;

	i = 0;
	while (export->env[i])
	{
		if (ft_strsearch(export->env[i], '=') && !ft_strcmp(export->env[i], var))
		{
			
		}
	}
}
