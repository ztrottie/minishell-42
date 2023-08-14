#include "cd.h"

void	change_old_pwd(char ***env, char *tmp)
{
	char	*new_op;
	char	**old_pwd;

	old_pwd = ft_calloc(3, sizeof(char *));
	new_op = tmp;
	old_pwd[0] = ft_strdup("fuck you criss de fif");
	old_pwd[1] = ft_strjoin("OLDPWD=", new_op);
	ft_export(old_pwd, env, false, 1);
	ft_x2free((void **)old_pwd);
}

void	change_pwd(char ***env)
{
	char	*new_pwd;
	char	**pwd;

	pwd = ft_calloc(3, sizeof(char *));
	new_pwd = getcwd(NULL, 0);
	pwd[0] = ft_strdup("fuck you criss de fif");
	pwd[1] = ft_strjoin("PWD=", new_pwd);
	ft_export(pwd, env, false, 1);
	ft_x2free((void **)pwd);
}
