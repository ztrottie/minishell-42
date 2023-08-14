#ifndef CD_H
# define CD_H

# include "../../../include/minishell.h"
# include "../export/export.h"

int	cd(char **av, char ***env);
void	change_pwd(char ***env);
void	change_old_pwd(char ***env, char *tmp);

#endif