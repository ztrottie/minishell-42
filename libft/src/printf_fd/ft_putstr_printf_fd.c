/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:27:07 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/29 14:39:33 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_fd.h"
#include "../../includes/string.h"

int	ft_putstr_printf_fd(char *s, int fd)
{
	if (!s)
		s = "(null)";
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}
