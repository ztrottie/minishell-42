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