/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:18:14 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/16 10:31:13 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "../../../include/minishell.h"

int			ft_exit(int ac, char **av, long long *exit_code);
int			ft_islonglong(char *str);
long long	ft_atoi_l(const char *str);

#endif