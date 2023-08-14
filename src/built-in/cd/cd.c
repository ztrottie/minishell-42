#include "cd.h"

static char	*get_path_name(char **env, char *name)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(name);
	while (*env && env[i])
	{
		if (strncmp(env[i], name, len) == 0)
			return (env[i] + len);
		i++;
	}
	return (NULL);
}

static void	change_old_pwd(char ***env)
{
	char	*new_op;
	char	**old_pwd;

	old_pwd = ft_calloc(3, sizeof(char *));
	new_op = getcwd(NULL, 0);
	old_pwd[0] = ft_strdup("fuck you criss de fif");
	old_pwd[1] = ft_strjoin("OLDPWD=", new_op);
	ft_export(old_pwd, env, false, 0);
	ft_x2free((void **)old_pwd);
}

static int	go_to_home(char **env)
{
	char	*dir;
	int		ch_dir;

	dir = NULL;
	if (*env)
		dir = get_path_name(env, "HOME=");
	if (!dir || !*dir)
	{
		ft_printf_fd(2, "minishell: cd: HOME not set\n");
		return (1);
	}
	ch_dir = chdir(dir);
	if (ch_dir)
	{
		ft_printf_fd(2, "minishell: cd: %s is not a directory\n", dir);
		return (1);
	}
	return (ch_dir);
}

static int	go_to_dir(char *content, char **env)
{
	int		ch_dir;
	char	*temp;

	if (ft_strncmp(content, "-", 2) == 0)
	{
		temp = get_path_name(env, "OLDPWD=");
		if (temp)
			content = temp;
		else
		{
			ft_printf_fd(2, "minishell: cd: OLDPWD not set\n");
			return (1);
		}
	}
	change_old_pwd(&env);
	ch_dir = chdir(content);
	if (ch_dir)
	{
		ft_printf_fd(2, "minishell: cd: %s is not a directory\n", content);
		return (1);
	}
	return (ch_dir);
}

int	cd(char **av, char ***env)
{
	int	len;

	len = ft_x2strlen(av);
	if (len == 1)
		return (go_to_home(*env));
	return (go_to_dir(av[1], *env));
}
