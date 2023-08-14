/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:50:35 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:50:52 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwd.h"

int	pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("minishell:");
		return (1);
	}
	ft_printf("%s\n", pwd);
	ft_free(pwd);
	return (SUCCESS);
}
