#include "../../include/execution.h"

static int	is_builtin(char *name)
{
	if (ft_strncmp("echo", name, ft_strlen(name)) == 0)
		return (VALID);
	if (ft_strncmp("export", name, ft_strlen(name)) == 0)
		return (VALID);
	if (ft_strncmp("unset", name, ft_strlen(name)) == 0)
		return (VALID);
	if (ft_strncmp("env", name, ft_strlen(name)) == 0)
		return (VALID);
	if (ft_strncmp("cd", name, ft_strlen(name)) == 0)
		return (VALID);
	return (INVALID);
}

static int	is_command(char *cmd_name)
{
	int	i;

	i = 0;
	while (cmd_name[i])
	{
		if (cmd_name[i] == '/')
			return (INVALID);
		i++;
	}
	return (VALID);
}

static int	get_cmd_type(char *cmd_name)
{
	if (is_command(cmd_name))
	{
		if (is_builtin(cmd_name))
			return (BUILTIN);
		else
			return (COMMAND);
	}
	else
		return (GIVEN);
}

int	child_process(t_data *data, int cmd_nb)
{
	int		type;
	char	*path;

	type = get_cmd_type(data->cmds[cmd_nb].name);
	if (get_in_out(&data->cmds[cmd_nb]) <= 0)
		exit(1);
	if (close_all(data, false) <= 0)
		exit(1);
	if (get_cmd_path(data, cmd_nb, type, &path) <= 0)
		return (FAILURE);
	if (execve(path, data->cmds[cmd_nb].content, data->env) < 0)
		perror("EXECVE");
	exit(0);
}
