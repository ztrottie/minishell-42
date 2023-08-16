/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:18:11 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/16 10:37:14 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	ft_exit(int ac, char **av, long long *exit_code)
{
	if (ac > 2)
	{
		return (ft_printf_fd(2, "exit\nminishell: exit: too many arguments\n"), \
		FAILURE);
	}
	if (ac == 2)
	{
		if (ft_islonglong(av[1]))
			*exit_code = ft_atoi_l(av[1]);
		else
		{
			ft_printf_fd(2, "exit\nminishell: exit: numeric argument required\n");
			exit(255);
		}
	}
	*exit_code = (unsigned)(int8_t)*exit_code;
	return (SUCCESS);
}
