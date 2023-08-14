/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:55:43 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 15:34:44 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putnbr_printf(int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = n * -1;
		ft_putchar_fd('-', 1);
	}
	else
		nbr = n;
	if (nbr / 10 != 0)
		ft_putnbr_fd(nbr / 10, 1);
	ft_putchar_fd(nbr % 10 + '0', 1);
	return (ft_putnbr_len(n));
}
