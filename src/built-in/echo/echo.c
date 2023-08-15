/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:17:55 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/15 13:42:05 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

static int	check_if_option(char **content)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (content[i] && content[i][0] == '-')
	{
		j = 1;
		if (ft_strncmp("-n", content[i], 2) == 0)
		{
			while (content[i][j] == 'n')
				j++;
			if (!content[i][j])
				count++;
			else
				return (count);
		}
		i++;
	}
	return (count);
}

int	echo(char **content)
{
	int	i;

	i = check_if_option(content) + 1;
	while (content[i])
	{
		ft_printf("%s", content[i]);
		if (content[i + 1])
			ft_printf(" ");
		i++;
	}
	if (check_if_option(content) == 0)
		ft_printf("\n");
	return (SUCCESS);
}
