/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:17:19 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:17:20 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"
# include "error.h"

char	*env_variable(t_data *data, char *name);
size_t	variable_content_len(t_data *data, char *line_read);
char	*variable_name(char *line);
size_t	variable_name_len(char *line);
int		is_valid_var(int c);
int		cpy_env(t_data *data, char **env);

#endif