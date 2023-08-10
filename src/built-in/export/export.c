#include "../../../include/built_in.h"

char    **add_environement(char **cpy_env, char *content, int option)
{
	int		i;
	int		j;
	char **env;

	env = ft_calloc(ft_x2strlen(cpy_env) + 2, sizeof(char *));
	if (!env)
		return (NULL);
	j = 0;
	i = 0;
	while (cpy_env[i])
	{
		if (option == 1 && ft_strsearch(cpy_env[i], '='))
			env[j++] = ft_strdup(cpy_env[i]);
		else if (option != 1)
			env[i] = ft_strdup(cpy_env[i]);
		i++;
	}
	if (option == 2)
	{
		env[i] = ft_strdup(content);
		return (ft_x2free((void **)cpy_env), env);
	}
	return (env);
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

static void	export_env(t_export *export, int fd)
{
	int	i;

	i = 0;
	export->env = ft_sort_params(ft_x2strlen(export->env), export->env);
	while (export->env[i])
	{
		ft_printf_fd(fd, "declare -x %s\n", export->env[i]);
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

static	int	parse_new_var(char *var, int *exit_code)
{
	int	i;

	i = 0;
	if (!ft_isalpha(var[0]) && var[0] != '_')
	{
		*exit_code = 1;
		ft_printf_fd(2, "minishell: export: `%s : not a valid identifier\n", var);
		return (INVALID);
	}
	while (var[i])
	{
		if (var[i] == '=' || (var[i] == '+' && var[i + 1] == '='))
			break ;
		if ((!ft_isalnum(var[i]) && var[i] != '_') || var[i] == ' ')
		{
			*exit_code = 1;
			ft_printf_fd(2, "minishell: export: `%s : not a valid identifier\n", var);
			return (INVALID);
		}
		i++;
	}
	return (SUCCESS);
}

static int	export_var(char *content, t_data *data)
{
	char	*var;
	char	**env;
	int		j;

	j = 0;
	env = data->export->env;
	while (env[j])
	{
		var = var_name(content);
		if (!ft_strcmp(env[j], var))
			return (SUCCESS);
		j++;
	}
	env = add_environement(env, content, 2);
	data->export->env = env;
	return (FAILURE);
}

int	ft_export(char **content, t_data *data, int fd, bool fork)
{
	int	i;
	int	exit_code;

	i = 1;
	exit_code = 0;
	if (!data->export)
	{
		data->export = ft_calloc(1, sizeof(t_export));
		if (!data->export)
			return (FAILURE);
		data->export->env = cpy_environement(data->env);
	}
	if (!content[1])
		export_env(data->export, fd);
	else
	{
		while (content[i])
		{
			if (parse_new_var(content[i], &exit_code))
				export_var(content[i], data);
			i++;
		}
	}
	data->env = add_environement(data->export->env, NULL, 1);
	return (exit_or_reset(fork, exit_code));
}
