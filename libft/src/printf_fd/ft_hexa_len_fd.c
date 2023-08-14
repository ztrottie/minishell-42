/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_len_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:07:28 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/29 14:30:50 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"

size_t	ft_hexa_len_fd(size_t nbr)
{
	size_t	i;
	size_t	nb;

	i = 0;
	if (nbr == 0)
		return (1);
	else
		nb = nbr;
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}
