/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:45:05 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/07 09:44:37 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putnbr_base_ul(unsigned long nbr)
{
	unsigned long	nb;
	char			*hexa;

	hexa = "0123456789abcdef";
	nb = nbr;
	if (nb / 16 != 0)
		ft_putnbr_base_ul((nb / 16));
	ft_putchar_fd(hexa[nb % 16], 1);
	return (ft_hexa_len(nbr));
}
