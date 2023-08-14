#include "../../include/execution.h"

static int	get_given_path(t_data *data, int cmd_nb, char **path)
{
	*path = ft_strdup(data->cmds[cmd_nb].name);
	if (!*path)
		return (FAILURE);
	if (access(data->cmds[cmd_nb].name, F_OK | X_OK) < 0)
	{
		ft_free(*path);
		path_error(data, cmd_nb, errno, NULL);
	}
	return (SUCCESS);
}

static int	get_builtin_path(t_data *data, int cmd_nb, char **path)
{
	*path = ft_strjoin(BUILTIN_BIN, data->cmds[cmd_nb].name);
	if (!*path)
		return (FAILURE);
	if (access(*path, F_OK | X_OK) < 0)
	{
		ft_free(*path);
		if (errno == EACCES)
			path_error(data, cmd_nb, errno, NULL);
		else
			path_error(data, cmd_nb, COMMAND_NOT_FOUND, NULL);
	}
	return (SUCCESS);
}

static int	split_path(t_data *data, char ***splited_path)
{
	char	**temp;
	char	*path;
	int		i;

	path = env_variable(data, "PATH");
	if (path == NULL)
		return (COMMAND_NOT_FOUND);
	temp = ft_split(path, ':');
	if (!temp)
		return (ft_free(path), FAILURE);
	*splited_path = ft_calloc(ft_x2strlen(temp) + 1, sizeof(char *));
	if (!*splited_path)
		return (ft_free(path), ft_x2free((void **)temp), \
		print_error("malloc"), FAILURE);
	i = 0;
	while (temp[i])
	{
		splited_path[0][i] = ft_strjoin(temp[i], "/");
		if (!splited_path[0][i])
			return (ft_free(path), ft_x2free((void **)*splited_path), \
			ft_x2free((void **)temp), FAILURE);
		i++;
	}
	return (ft_x2free((void **)temp), ft_free(path), SUCCESS);
}

static int	get_command_path(t_data *data, int cmd_nb, char **path)
{
	char	**splited_path;
	char	*full_path;
	int		i;

	if (split_path(data, &splited_path) <= 0)
		path_error(data, cmd_nb, COMMAND_NOT_FOUND, NULL);
	i = 0;
	while (splited_path[i])
	{
		full_path = ft_strjoin(splited_path[i], data->cmds[cmd_nb].name);
		if (access(full_path, F_OK) == 0)
			break ;
		ft_free(full_path);
		i++;
	}
	if (!splited_path[i])
		path_error(data, cmd_nb, COMMAND_NOT_FOUND, splited_path);
	if (access(full_path, X_OK) < 0)
		path_error(data, cmd_nb, errno, splited_path);
	*path = full_path;
	return (SUCCESS);
}

int	get_cmd_path(t_data *data, int cmd_nb, int type, char **path)
{
	if (type == GIVEN)
	{
		if (get_given_path(data, cmd_nb, path) <= 0)
			return (FAILURE);
	}
	else if (type == BUILTIN)
	{
		if (get_builtin_path(data, cmd_nb, path) <= 0)
			return (FAILURE);
	}
	else
		if (get_command_path(data, cmd_nb, path) <= 0)
			return (FAILURE);
	return (SUCCESS);
}
