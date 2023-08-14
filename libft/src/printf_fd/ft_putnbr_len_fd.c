/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:06:22 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/29 14:30:33 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"

int	ft_putnbr_len_fd(long int n)
{
	unsigned int	nbr;
	int				i;

	i = 0;
	if (n < 0)
	{
		nbr = n * -1;
		i++;
	}
	else if (n == 0)
		return (1);
	else
		nbr = n;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
