/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:18:30 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:18:31 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

static char	*var_name(char *content)
{
	int		i;
	char	*name;

	i = 0;
	while (content[i])
	{
		if (content[i] == '+' || content[i] == '=')
			break ;
		i++;
	}
	name = ft_calloc(sizeof(char), i + 1);
	if (!name)
		return (NULL);
	ft_strlcpy(name, content, i + 1);
	return (name);
}

static	int	parse_new_var(char *var, int *exit_code)
{
	int	i;

	i = 0;
	if (!ft_isalpha(var[0]) && var[0] != '_')
	{
		*exit_code = 1;
		ft_printf_fd(2, "minishell: export: `%s : not a valid identifier\n", \
		var);
		return (INVALID);
	}
	while (var[i])
	{
		if (var[i] == '=' || (var[i] == '+' && var[i + 1] == '='))
			break ;
		if ((!ft_isalnum(var[i]) && var[i] != '_') || var[i] == ' ')
		{
			*exit_code = 1;
			ft_printf_fd(2, "minishell: export: `%s : not a valid identifier\n", \
			var);
			return (INVALID);
		}
		i++;
	}
	return (SUCCESS);
}

static int	export_var(char *content, char ***env)
{
	char	*var;
	int		type;
	int		j;

	var = var_name(content);
	type = check_type(content, ft_strlen(var));
	j = 0;
	while (env[0][j])
	{
		if (ft_strncmp(env[0][j], var, ft_strlen(var)) == 0)
			return (ft_free(var), type_choice(&env[0][j], content, type));
		j++;
	}
	if (create_var(content, env, type) <= 0)
		return (ft_free(var), FAILURE);
	return (ft_free(var), SUCCESS);
}

int	ft_export(char **argv, char ***env, int fd)
{
	int	i;
	int	exit_code;

	i = 1;
	exit_code = 0;
	if (!argv[1])
		export_env(*env, fd);
	else
	{
		while (argv[i])
		{
			if (parse_new_var(argv[i], &exit_code))
				export_var(argv[i], env);
			i++;
		}
	}
	return (exit_code);
}
