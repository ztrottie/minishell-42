#include "../../include/built_in.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static char    **ft_sort_params(int nbr_param, char **tabexport)
{
    int        i;
    int        j;
    char    *temp;

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

static void	export_env(t_export *export)
{
	int	i;

	i = 0;
	export->env = ft_sort_params(ft_x2strlen(export->env), export->env);
	while (export->env[i])
	{
		ft_printf("declare -x %s\n", export->env[i]);
		i++;
	}
}

static char	*var_name(char *content)
{
	int		i;
	char	*name;

	i = 0;
	while (content[i])
	{
			if (content[i] != '+' || content[i] != '=')
				break ;
		i++;
	}
	name = ft_calloc(sizeof(char), i + 1);
	if (!name)
		return (NULL);
	ft_strlcpy(name, &content[i], i + 1);
	return (name);
}

static	int	parse_new_var(char *var, int exit_code)
{
	int	i;

	i = 0;
	if (!ft_isalpha(var[0]) || var[0] != '_')
	{
		exit_code = 1;
		ft_printf_fd(2, "minishell: export: `%s : not a valid identifier\n");
		return (FAILURE);
	}
	while (var[i])
	{
		if (var[i] == '=' || var[i] == '_' || var[i + 1] == '_')
			break ;
		if (!ft_isalnum(var[i]) || var[i] != '=')
		{
			exit_code = 1;
			ft_printf_fd(2, "minishell: export: `%s : not a valid identifier\n");
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static int	export_var(char **content, t_export *export, int exit_code)
{
	int			i;
	char	*var;

	i = 0;
	while (content[i])
	{
		var = var_name(content[i]);
		if (parse_new_var(var, exit_code))
		{
			
		}
		i++;
	}
	return (FAILURE);
}

int	ft_export(char **content, t_export *export)
{
	int	i;
	int	exit_code;

	i = 1;
	exit_code = 0;
	if (!content[1])
		export_env(export);
	else
	{
	}
	return (exit_or_return(&fork, exit_code));
}
