/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:31:42 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/07 09:44:48 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char maj)
{
	unsigned int	nb;
	char			*hexa;

	if (maj == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	nb = nbr;
	if (nb / 16 != 0)
		ft_putnbr_base((nb / 16), maj);
	ft_putchar_fd(hexa[nb % 16], 1);
	return (ft_hexa_len(nbr));
}
