/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strishexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:10:50 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/14 10:27:25 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/conversion.h"

int	ft_strishexa(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		if (!(str[i] >= '0' && str[i] <= '9') \
		|| !(str[i] >= 'A' && str[i] <= 'F'))
			return (1);
		i++;
	}
	return (0);
}
