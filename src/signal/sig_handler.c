#include "../../include/signal.h"

static void	sig_hd(int sig)
{
	(void)sig;
}

static void	default_sig(int sig)
{
	(void)sig;
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

static void	back_slash(int sig)
{
	if (sig == SIGINT)
		ft_printf("\n");
	else if (sig == SIGQUIT)
		ft_printf_fd(2, "Quit: 3\n");
}

void	sig_handler(int type)
{
	if (type == SIGHD)
	{
		signal(SIGINT, sig_hd);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (type == SIGDEFAULT)
	{
		signal(SIGINT, default_sig);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (type == SIGPARENT)
	{
		signal(SIGINT, back_slash);
		signal(SIGQUIT, back_slash);
	}
	else if (type == SIGCHILD)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}
