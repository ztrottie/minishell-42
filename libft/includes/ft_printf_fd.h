/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:28:34 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/29 14:40:54 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <stdarg.h>
# include <unistd.h>
# include "write_fd.h"

int		ft_printf_fd(int fd, const char *str, ...);
int		ft_pointer_fd(unsigned long ptr, int fd);
int		ft_putstr_printf_fd(char *s, int fd);
int		ft_putnbr_base_fd(unsigned int nbr, char maj, int fd);
int		ft_putnbr_printf_fd(int n, int fd);
int		ft_putnbr_len_fd(long int n);
size_t	ft_hexa_len_fd(size_t nbr);
int		ft_putnbr_u_fd(unsigned int nb, int fd);
int		ft_putnbr_base_ul_fd(unsigned long nbr, int fd);

#endif