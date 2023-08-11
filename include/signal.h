#ifndef SIGNAL_H
# define SIGNAL_H

# include <signal.h>
# include "minishell.h"
# include "redirection.h"

void	sig_handler(int type);

enum e_sig_type
{
	SIGHD = 1,
	SIGDEFAULT = 2,
	SIGBACKSLASH = 3,
	SIGPARENT = 4,
	SIGCHILD = 5,
};

#endif