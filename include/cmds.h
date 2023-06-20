/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:15:28 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/20 01:45:58 by ztrottie         ###   ########.fr       */
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
char 	**split_command(char *line);
int		is_metachar(int c);
int		is_operator(char *line, int	index);
size_t	nb_metachar(char *line);

#endif