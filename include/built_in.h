#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"
# include "env.h"

int	pwd(void);
int	print_env(char **env);
int	export(t_data *data);
int	cd(t_data *data);
int	ft_unset(t_data *data, char **variable);
int	echo(char **content);

#endif