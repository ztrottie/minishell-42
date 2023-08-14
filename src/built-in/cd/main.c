/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:17:51 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:17:52 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

static char	**cpy_envi(char **cpy_env)
{
	int		i;
	char	**env;

	i = 0;
	while (cpy_env[i])
		i++;
	env = ft_calloc(i + 1, sizeof(char *));
	if (!env)
		return (NULL);
	i = 0;
	while (cpy_env[i])
	{
		env[i] = ft_strdup(cpy_env[i]);
		i++;
	}
	return (env);
}

int	main(int ac, char **av, char **env)
{
	char	**cpy_env;

	(void)ac;
	cpy_env = cpy_envi(env);
	cd(av, &cpy_env);
	ft_x2free((void **)cpy_env);
	return (0);
}
