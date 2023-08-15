/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:21:01 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/15 12:30:12 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/signal.h"

int	g_exit_code = 0;

static void	sig_hd(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf_fd(STDERR_FILENO, "\n");
		close(STDIN_FILENO);
	}
}

static void	default_sig(int sig)
{
	(void)sig;
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_code = 1;
}

static void	back_slash(int sig)
{
	if (sig == SIGINT)
		ft_printf("\n");
	else if (sig == SIGQUIT)
		ft_printf_fd(2, "Quit: 3\n");
}

void	sig_handler_c(bool is_heredoc)
{
	if (is_heredoc == true)
	{
		signal(SIGINT, sig_hd);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}

void	sig_handler_p(bool mute, bool is_interactive)
{
	if (mute == true)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (is_interactive == true)
	{
		signal(SIGINT, default_sig);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, back_slash);
		signal(SIGQUIT, back_slash);
	}
}
