#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"
# include "env.h"
# include "error.h"

int		pwd(int fd);
int		print_env(char **env, int fd);
int		ft_export(char **content, t_export *export, t_data *data);
int		cd(t_data *data);
int		ft_unset(t_data *data, char **content, t_export *export, bool fork);
int		echo(char **content);
char    **cpy_environement(char **env, char **cpy_env);
int		ft_strsearch(char *str, char reject);
void	check_if_exist(t_export *export, char *var);


#endif