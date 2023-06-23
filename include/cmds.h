/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:15:28 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/22 22:07:05 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDS_H
# define CMDS_H

# include "minishell.h"

typedef struct s_lines
{
	char		*line;
	char		*parsed_line;
	size_t		i_line;
	size_t		i_parsed_line;
}	t_lines;

void	commands_init(t_data *data, char *line);
char 	**split_command(t_data *data, char *line);
int		is_metachar(int c);
int		is_operator(char *line, int	index);
size_t	nb_metachar(char *line);
int		is_quote(int c);
void	single_quote_control(t_lines *lines);
void	double_quote_control(t_data *data, t_lines *lines);
void	cpy_env(t_data *data, char **env);
char 	*env_variable(t_data *data, char *variable);

#endif