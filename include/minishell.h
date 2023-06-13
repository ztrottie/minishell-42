/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:03:42 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/07 14:05:33 by ztrottie         ###   ########.fr       */
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
# include <unistd.h>
# include "parsing.h"

typedef struct	s_commands
{
	char	*name;
	char	*args;
	char	*content;
}	t_commands;

typedef	struct	s_pipe
{
	t_commands	*cmd1;
	t_commands	*cmd2;
}	t_pipe;


#endif