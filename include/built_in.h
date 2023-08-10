#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"
# include "env.h"

int		ft_unset(char **argv, char ***env, bool fork);
int		ft_export(char **argv, char ***env, bool fork, int fd);

#endif