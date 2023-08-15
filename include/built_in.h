/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:17:13 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/15 11:09:13 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"
# include "env.h"

int		ft_unset(char **argv, char ***env);
int		ft_export(char **argv, char ***env, int fd);
int		cd(char **av, char ***env, t_data *data);
int		ft_exit(int ac, char **av, long long exit_code, bool fork);

#endif