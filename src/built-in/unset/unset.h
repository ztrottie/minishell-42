/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:19:01 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:19:02 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H
# define UNSET_H

# include "../../../include/minishell.h"

int	parse_var(char *var, int *exit_code);
int	exit_or_reset(bool fork, int exit_code);
int	ft_unset(char **content, char ***env);

#endif