#include "export.h"

static char	**ft_sort_params(int nbr_param, char **tabexport)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < nbr_param)
	{
		j = i + 1;
		while (j < nbr_param)
		{
			if (ft_strcmp(tabexport[j], tabexport[i]) < 0)
			{
				temp = tabexport[i];
				tabexport[i] = tabexport[j];
				tabexport[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tabexport);
}

void	export_env(char **env, int fd)
{
	int		i;
	int		len;
	char	**env_sorted;
	char	*name;

	i = 0;
	if (fd > 0)
	{
		env_sorted = ft_sort_params(ft_x2strlen(env), env);
		while (env_sorted[i])
		{
			len = 0;
			while (env[i][len] && env[i][len] != '=')
				len++;
			name = ft_substr(env[i], 0, len);
			if (env[i][len] == '=')
				ft_printf_fd(fd, "declare -x %s=\"%s\"\n", \
					name, env_sorted[i] + len + 1);
			else
				ft_printf_fd(fd, "declare -x %s\n", name);
			ft_free(name);
			i++;
		}
	}
}
