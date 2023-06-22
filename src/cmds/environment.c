/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:04:34 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/22 17:19:36 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cmds.h"

void	cpy_env(t_data *data, char **env)
{
	int	i;
	
	i = 0;
	data->env = ft_calloc(ft_x2strlen((const char **)env), sizeof(char *));
	while (env[i])
	{
		data->env[i] = ft_calloc(ft_strlen(env[i]), sizeof(char));
		data->env[i] = ft_memcpy(data->env[i], env[i], ft_strlen(env[i]));
		i++;
	}
}

char *env_variable(t_data *data, char *variable)
{
	int	i;

	i = 0;
	if (!data->env)
		return (NULL);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], variable, ft_strlen(variable)) == 0)
			return (data->env[i] + ft_strlen(variable) + 1);
		i++;
	}
	return (NULL);
}
