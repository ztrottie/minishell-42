/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:06:25 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 15:33:53 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_define_ft(char c, va_list arg)
{
	int	count;

	count = 1;
	if (c == 'c')
		ft_putchar_fd(va_arg(arg, int), 1);
	else if (c == 's')
		count = ft_putstr_printf(va_arg(arg, char *));
	else if (c == 'p')
		count = ft_pointer(va_arg(arg, unsigned long));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_printf(va_arg(arg, int));
	else if (c == 'u')
		count = ft_putnbr_u(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_putnbr_base(va_arg(arg, unsigned int), c);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *str, ...)
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
			count += ft_define_ft(str[i + 1], arg);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
