#include "../../include/execution.h"

static int call_exit(t_data *data)
{
	int		tmp;
	char	**content;
	size_t	len;
	int		i;

	len = ft_x2strlen(data->cmds->content);
	tmp = data->exit_code;
	content = ft_calloc(len + 1, sizeof(char *));
	if (!content)
		return (print_error("malloc"), FAILURE);
	i = 0;
	while (data->cmds->content[i])
	{
		content[i] = ft_strdup(data->cmds->content[i]);
		i++;
	}
	free_all(data, true);
	ft_exit(len, content, tmp, true);
	return (SUCCESS);
}

int	check_builtin_nofork(t_data *data)
{
	if (ft_strcmp(data->cmds->name, "export") == 0)
		return (VALID);
	if (ft_strcmp(data->cmds->name, "unset") == 0)
		return (VALID);
	if (ft_strcmp(data->cmds->name, "cd") == 0)
		return (VALID);
	if (ft_strcmp(data->cmds->name, "exit") == 0)
		return (VALID);
	return (INVALID);
}

int	exec_nofork(t_data *data)
{
	int	fd;

	if (data->cmds->input && data->cmds->input->fd < 0)
		return (SUCCESS);
	if (data->cmds->output)
		fd = data->cmds->output->fd;
	else
		fd = 1;
	sig_handler_c(false);
	if (ft_strcmp(data->cmds->name, "export") == 0)
		data->exit_code = ft_export(data->cmds->content, &data->env, fd);
	if (ft_strcmp(data->cmds->name, "unset") == 0)
		data->exit_code = ft_unset(data->cmds->content, &data->env);
	if (ft_strcmp(data->cmds->name, "cd") == 0)
		data->exit_code = cd(data->cmds->content, &data->env);
	if (ft_strcmp(data->cmds->name, "exit") == 0)
		call_exit(data);
	return (SUCCESS);
}
