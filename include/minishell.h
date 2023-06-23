/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:03:42 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/22 22:11:31 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

# define METACHAR "|<>"
# define SINGLE_QUOTE 1
# define DOUBLE_QUOTE 2
# define SUCCES 0
# define FAILURE 1

typedef struct	s_files
{
	char			*name;
	int				fd;
	int				cmd_nb;
}	t_files;

typedef struct	s_cmds
{
	int		nb;
	char	*name;
	char	*args;
	char	**content;
	int		nb_input;
	t_files	*input_fds;
	int		nb_output;
	t_files	*output_fds;
}	t_cmds;

typedef struct	s_data
{
	t_cmds	*cmds;
	int		**pipe;
	int		nb_cmds;
	char	**env;
	t_files	*input_fds;
	t_files	*output_fds;
}	t_data;

#endif