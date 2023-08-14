/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:55:43 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/29 14:42:32 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"

int	ft_putnbr_printf_fd(int n, int fd)
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
		ft_putnbr_printf_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
	return (ft_putnbr_len_fd(n));
}
