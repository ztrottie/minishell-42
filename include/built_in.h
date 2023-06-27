#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"
# include "env.h"

int	pwd(t_data *data);
int	print_env(char **env);
int	export(t_data *data);
int	cd(t_data *data);
int	unset(t_data *data);
int	echo(char **content);

#endif