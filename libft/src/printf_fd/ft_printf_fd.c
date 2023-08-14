/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:06:25 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/29 14:41:50 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"

static int	ft_define_ft(char c, va_list arg, int fd)
{
	int	count;

	count = 1;
	if (c == 'c')
		ft_putchar_fd(va_arg(arg, int), fd);
	else if (c == 's')
		count = ft_putstr_printf_fd(va_arg(arg, char *), fd);
	else if (c == 'p')
		count = ft_pointer_fd(va_arg(arg, unsigned long), fd);
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_printf_fd(va_arg(arg, int), fd);
	else if (c == 'u')
		count = ft_putnbr_u_fd(va_arg(arg, unsigned int), fd);
	else if (c == 'x' || c == 'X')
		count = ft_putnbr_base_fd(va_arg(arg, unsigned int), c, fd);
	else if (c == '%')
		ft_putchar_fd('%', fd);
	return (count);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, str);
	if (!str)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			count += ft_define_ft(str[i + 1], arg, fd);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], fd);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
