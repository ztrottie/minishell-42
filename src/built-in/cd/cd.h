/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:17:48 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:21:38 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include "../../../include/minishell.h"
# include "../export/export.h"

int		cd(char **av, char ***env);
void	change_pwd(char ***env);
void	change_old_pwd(char ***env, char *tmp);

#endif