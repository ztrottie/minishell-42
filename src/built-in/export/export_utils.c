/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:18:28 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:18:29 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	check_type(char *content, int index)
{
	if (content[index] == '=')
		return (TRUNC);
	else if (content[index] == '+')
		return (ADD);
	return (INVALID);
}

int	is_complete(char *var)
{
	size_t	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			return (VALID);
		i++;
	}
	return (INVALID);
}
