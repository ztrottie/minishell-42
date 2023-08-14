/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:17:38 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:17:39 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include <signal.h>
# include "minishell.h"
# include "redirection.h"

void	sig_handler_p(bool mute, bool is_interactive);
void	sig_handler_c(bool is_heredoc);

enum e_sig_type
{
	SIGHD = 1,
	SIGDEFAULT = 2,
	SIGBACKSLASH = 3,
	SIGPARENT = 4,
	SIGCHILD = 5,
};

#endif