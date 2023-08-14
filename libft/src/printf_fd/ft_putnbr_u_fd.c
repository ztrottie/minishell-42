/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:45:59 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/29 14:39:41 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr / 10 != 0)
		ft_putnbr_u_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
	return (ft_putnbr_len_fd(n));
}
