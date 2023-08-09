#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"
# include "env.h"
# include "error.h"

int		ft_export(char **content, t_data *data, int fd, bool fork);
int		cd(t_data *data);
int		ft_unset(t_data *data, char **content, t_export *export, bool fork);
char    **cpy_environement(char **cpy_env);
int		ft_strsearch(char *str, char reject);
void	check_if_exist(t_export *export, char *var);


#endif