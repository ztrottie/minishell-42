#include "../../include/commands.h"

int	pid_add_end(t_pid_list **pid_list, pid_t pid)
{
	t_pid_list	*ptr;

	if (!*pid_list)
	{
		*pid_list = ft_calloc(1, sizeof(t_pid_list));
		if (!*pid_list)
			return (print_error("malloc"), FAILURE);
		(*pid_list)->pid = pid;
	}
	else
	{
		ptr = *pid_list;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = ft_calloc(1, sizeof(t_pid_list));
		if (!ptr->next)
			return (print_error("malloc"), FAILURE);
		ptr->next->pid = pid;
	}
	return (SUCCESS);
}

void	free_pid_list(t_data *data)
{
	t_pid_list	*ptr;
	t_pid_list	*tmp;

	ptr = data->pid_list;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		ft_free(ptr);
		ptr = tmp;
	}
	data->pid_list = NULL;
}

int	wait_pid_list(t_data *data)
{
	t_pid_list	*ptr;
	int			status;

	ptr = data->pid_list;
	while (ptr != NULL)
	{
		if (waitpid(ptr->pid, &status, 0) < 0)
			return (FAILURE);
		if (WIFEXITED(status))
			data->exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			data->exit_code = WTERMSIG(status) + 128;
		ptr = ptr->next;
	}
	return (SUCCESS);
}
