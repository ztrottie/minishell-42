#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"
# include "env.h"
# include "error.h"

int		ft_unset(t_data *data, char **content, t_export *export, bool fork);
int		ft_export(char **argv, char ***env, bool fork, int fd);


#endif