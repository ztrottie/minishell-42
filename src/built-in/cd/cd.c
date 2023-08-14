/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:17:46 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:17:47 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

static char	*get_path_name(char **env, char *name)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(name);
	while (*env && env[i])
	{
		if (strncmp(env[i], name, len) == 0)
			return (env[i] + len);
		i++;
	}
	return (NULL);
}

static int	go_to_home(char ***env)
{
	char	*dir;
	int		ch_dir;
	char	*tmp_pwd;

	dir = NULL;
	if (*env)
		dir = get_path_name(*env, "HOME=");
	if (!dir || !*dir)
	{
		ft_printf_fd(2, "minishell: cd: HOME not set\n");
		return (1);
	}
	tmp_pwd = getcwd(NULL, 0);
	ch_dir = chdir(dir);
	if (ch_dir)
	{
		ft_printf_fd(2, "minishell: cd: %s is not a directory\n", dir);
		return (1);
	}
	change_old_pwd(env, tmp_pwd);
	change_pwd(env);
	return (ch_dir);
}

static int	go_to_dir(char *content, char ***env)
{
	int		ch_dir;
	char	*temp;
	char	*tmp_pwd;

	if (ft_strncmp(content, "-", 2) == 0)
	{
		temp = get_path_name(*env, "OLDPWD=");
		if (temp)
			content = temp;
		else
		{
			ft_printf_fd(2, "minishell: cd: OLDPWD not set\n");
			return (1);
		}
	}
	tmp_pwd = getcwd(NULL, 0);
	ch_dir = chdir(content);
	if (ch_dir)
	{
		ft_printf_fd(2, "minishell: cd: %s is not a directory\n", content);
		return (1);
	}
	change_old_pwd(env, tmp_pwd);
	change_pwd(env);
	return (ch_dir);
}

int	cd(char **av, char ***env)
{
	int		len;

	len = ft_x2strlen(av);
	if (len == 1)
		return (go_to_home(env));
	return (go_to_dir(av[1], env));
}
