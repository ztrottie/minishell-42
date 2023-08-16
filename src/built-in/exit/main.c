/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:18:20 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/16 10:33:33 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	main(int ac, char **av)
{
	long long	exit_code;

	exit_code = 0;
	ft_exit(ac, av, &exit_code);
	return (exit_code);
}
