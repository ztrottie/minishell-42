#include "../../include/parsing.h"

int	red_add_end(t_red **red_list, int type, char *content)
{
	t_red	*ptr;

	if (!*red_list)
	{
		*red_list = ft_calloc(1, sizeof(t_red));
		if (!*red_list)
			return (FAILURE);
		(*red_list)->type = type;
		(*red_list)->content = content;
	}
	else
	{
		ptr = *red_list;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = ft_calloc(1, sizeof(t_red));
		if (!ptr->next)
			return (FAILURE);
		ptr->next->type = type;
		ptr->next->content = content;
	}
	return (SUCCESS);
}

void	free_red_list(t_red **red_list)
{
	t_red	*ptr;
	t_red	*tmp;

	ptr = *red_list;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		ft_free(ptr);
		ptr = tmp;
	}
}
