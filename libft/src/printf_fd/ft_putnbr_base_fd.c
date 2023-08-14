/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:31:42 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/29 14:37:37 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"

int	ft_putnbr_base_fd(unsigned int nbr, char maj, int fd)
{
	unsigned int	nb;
	char			*hexa;

	if (maj == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	nb = nbr;
	if (nb / 16 != 0)
		ft_putnbr_base_fd((nb / 16), maj, fd);
	ft_putchar_fd(hexa[nb % 16], fd);
	return (ft_hexa_len_fd(nbr));
}
