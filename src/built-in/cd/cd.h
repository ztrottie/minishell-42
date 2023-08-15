/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:17:48 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/15 10:47:13 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include "../../../include/minishell.h"
# include "../export/export.h"

int		cd(char **av, char ***env, t_data *data);
void	change_pwd(char ***env, t_data *data);
void	change_old_pwd(char ***env, char *tmp);

#endif