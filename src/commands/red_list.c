#include "../../include/parsing.h"

int	red_add_end(t_red **red_list, int type, char *content, int cont_type)
{
	t_red	*ptr;

	if (!*red_list)
	{
		*red_list = ft_calloc(1, sizeof(t_red));
		if (!*red_list)
			return (FAILURE);
		(*red_list)->type = type;
		(*red_list)->content = content;
		(*red_list)->cont_type = cont_type;
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
		ptr->cont_type = cont_type;
	}
	return (SUCCESS);
}

int	find_next_red(bool input, t_red *red)
{
	t_red *ptr;

	ptr = red;
	while (ptr != NULL)
	{
		if (input)
		{
			if (ptr->type == HERE_DOC || ptr->type == RED_IN)
				return (VALID);
		}
		else
			if (ptr->type == RED_OUT || ptr->type == RED_OUT_APPEND)
				return (VALID);
		ptr = ptr->next;
	}
	return (INVALID);
}

void	free_red_list(t_red **red_list)
{
	t_red	*ptr;
	t_red	*tmp;

	ptr = *red_list;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		if (ptr->type == HERE_DOC)
			ft_free(ptr->content);
		ft_free(ptr);
		ptr = tmp;
	}
	*red_list = NULL;
}
