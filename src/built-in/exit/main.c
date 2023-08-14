/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:18:20 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:18:21 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	main(int ac, char **av)
{
	int	exit_code;

	exit_code = 0;
	ft_exit(ac, av, exit_code, false);
	return (exit_code);
}
