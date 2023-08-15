/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:17:44 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/15 12:16:27 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

void	change_old_pwd(char ***env, char *tmp)
{
	char	*new_op;
	char	**old_pwd;

	old_pwd = ft_calloc(3, sizeof(char *));
	new_op = tmp;
	old_pwd[0] = ft_strdup("fuck you criss de fif");
	old_pwd[1] = ft_strjoin("OLDPWD=", new_op);
	ft_export(old_pwd, env, -1);
	ft_x2free((void **)old_pwd);
}

void	change_pwd(char ***env, t_data *data)
{
	char	*new_pwd;
	char	**pwd;

	pwd = ft_calloc(3, sizeof(char *));
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		ft_printf_fd(2, "cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n");
	if (data != NULL && new_pwd != NULL)
	{
		ft_free(data->pwd[1]);
		data->pwd[1] = new_pwd;
	}
	pwd[0] = ft_strdup("fuck you criss de fif");
	pwd[1] = ft_strjoin("PWD=", new_pwd);
	ft_export(pwd, env, -1);
	ft_x2free((void **)pwd);
}
