#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"
# include "env.h"
# include "error.h"

typedef struct s_export
{
	char	**env;
	int		exit_code;
	int		env_i;
}	t_export;


int		pwd(void);
int		print_env(char **env);
int		ft_export(char **content, t_export *export);
int		cd(t_data *data);
int		ft_unset(t_data *data, char **content, t_export *export, bool fork);
int		echo(char **content);
char    **cpy_environement(char **env, char **cpy_env);


#endif