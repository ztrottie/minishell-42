#ifndef EXPORT_H
# define EXPORT_H

# include "stdbool.h"
# include "../../../include/minishell.h"
# include "../../../include/env.h"

# define ADD 10
# define TRUNC 11

int		ft_export(char **argv, char ***env, int fd);
int		exit_or_return(bool fork, int exit_code);
void	export_env(char **env, int fd);
char	**cpy_environement(char **cpy_env);
int		create_var(char *content, char ***env, int type);
int		type_choice(char **env, char *content, int type);
int		check_type(char *content, int index);
int		is_complete(char *var);

#endif