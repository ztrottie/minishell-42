/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:19:35 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:19:36 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"

void	print_error(char *cause)
{
	ft_printf_fd(2, "minishell: ");
	perror(cause);
	ft_printf_fd(2, "\n");
}
