/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:49:10 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/20 01:45:52 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cmds.h"

int	is_operator(char *line, int	index)
{
	int	metachar_index;

	if (!line)
		return (0);
	metachar_index = is_metachar(line[index]);
	if (metachar_index > 0)
	{
		if (line[index + 1] && is_metachar(line[index + 1]) == metachar_index)
			return (2);
		return (1);
	}
	return (0);
}

size_t	nb_metachar(char *line)
{
	size_t	i;
	size_t	count;
	int		metachar_index;
	
	i = 0;
	count = 0;
	while (line[i])
	{
		metachar_index = is_metachar(line[i]);
		if (metachar_index > 0)
			count++;
		if (line[i + 1] && metachar_index == is_metachar(line[i + 1]))
			i++;
		i++;
	}
	return (count);
}

int	is_metachar(int c)
{
	int		i;

	i = 0;
	while (METACHAR[i])
	{
		if (METACHAR[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}
