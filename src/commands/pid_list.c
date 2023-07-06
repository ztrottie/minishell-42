#include "../../include/commands.h"

int	pid_add_end(t_data *data, pid_t pid)
{
	t_pid_list	*ptr;

	if (!data->pid)
	{
		ft_printf("ayo");
		data->pid = ft_calloc(1, sizeof(t_pid_list));
		if (!data->pid)
			return (FAILURE);
		data->pid->pid = pid;
	}
	else
	{
		ptr = data->pid;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = ft_calloc(1, sizeof(t_pid_list));
		if (!ptr->next)
			return (FAILURE);
		ptr->next->pid = pid;
	}
	return (SUCCESS);
}

void	free_pid_list(t_pid_list **pid_list)
{
	t_pid_list	*ptr;
	t_pid_list	*tmp;

	ptr = *pid_list;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		ft_free(ptr);
		ptr = tmp;
	}
	*pid_list = NULL;

}
