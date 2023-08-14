/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ul_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:45:05 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/29 14:42:24 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"

int	ft_putnbr_base_ul_fd(unsigned long nbr, int fd)
{
	unsigned long	nb;
	char			*hexa;

	hexa = "0123456789abcdef";
	nb = nbr;
	if (nb / 16 != 0)
		ft_putnbr_base_ul_fd((nb / 16), fd);
	ft_putchar_fd(hexa[nb % 16], fd);
	return (ft_hexa_len_fd(nbr));
}
