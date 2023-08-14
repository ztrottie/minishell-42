#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"
# include "env.h"

int	ft_unset(char **argv, char ***env);
int	ft_export(char **argv, char ***env, bool fork, int fd);
int	cd(char **av, char ***env);
int	ft_exit(int ac, char **av, long long exit_code);

#endif