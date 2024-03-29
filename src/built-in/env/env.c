/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:18:03 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:18:04 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	check_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (VALID);
		i++;
	}
	return (INVALID);
}

int	print_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (FAILURE);
	while (env[i])
	{
		if (check_valid(env[i]))
			ft_printf("%s\n", env[i]);
		i++;
	}
	return (SUCCESS);
}
