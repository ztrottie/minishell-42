#ifndef UNSET_H
# define UNSET_H

# include "../../../include/minishell.h"

int	parse_var(char *var, int *exit_code);
int	exit_or_reset(bool fork, int exit_code);
int	ft_unset(char **content, char ***env, bool fork);


#endif