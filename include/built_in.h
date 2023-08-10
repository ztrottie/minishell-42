#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"
# include "env.h"

int		ft_export(char **content, t_data *data, int fd, bool fork);
int		cd(t_data *data);
int		ft_unset(char **content, char ***env, bool fork);
char    **cpy_environement(char **cpy_env);
void	check_if_exist(t_export *export, char *var);
int		exit_or_reset(bool fork, int exit_code);



#endif