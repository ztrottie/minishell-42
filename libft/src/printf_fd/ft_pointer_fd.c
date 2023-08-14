/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:37:41 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/29 14:36:53 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"

int	ft_pointer_fd(unsigned long ptr, int fd)
{
	int	count;

	count = 2;
	if (!ptr)
	{
		write(fd, "0x0", 3);
		return (3);
	}
	write(fd, "0x", 2);
	count += ft_putnbr_base_ul_fd(ptr, fd);
	return (count);
}
