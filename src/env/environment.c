/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:19:29 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:53:01 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/env.h"

int	cpy_env(t_data *data, char **env)
{
	int	i;

	i = 0;
	data->env = ft_calloc(ft_x2strlen(env) + 1, sizeof(char *));
	if (!data->env)
		return (print_error("malloc"), FAILURE);
	while (env[i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) != 0)
		{
			data->env[i] = ft_calloc(ft_strlen(env[i]) + 1, sizeof(char));
			if (!data->env[i])
				return (FAILURE);
			data->env[i] = ft_memcpy(data->env[i], env[i], ft_strlen(env[i]));
		}
		else
		{
			data->env[i] = ft_calloc(8, sizeof(char));
			if (!data->env[i])
				return (print_error("malloc"), FAILURE);
			data->env[i] = ft_memcpy(data->env[i], "OLDPWD", 8);
		}
		i++;
	}
	return (SUCCESS);
}
