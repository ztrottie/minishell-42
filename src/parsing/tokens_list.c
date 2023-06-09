#include "../../include/parsing.h"

void	free_tokens(t_tokens **tokens)
{
	t_tokens	*tmp;
	t_tokens	*ptr;

	ptr = *tokens;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		ft_free(ptr->content);
		ft_free(ptr);
		ptr = tmp;
	}
}

int	token_add_end(t_tokens **tokens, int type, char *content)
{
	t_tokens	*ptr;

	if (!*tokens)
	{
		*tokens = ft_calloc(1, sizeof(t_tokens));
		if (!tokens)
			return (FAILURE);
		(*tokens)->content = content;
		(*tokens)->type = type;
	}
	else
	{
		ptr = *tokens;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = ft_calloc(1, sizeof(t_tokens));
		if (!ptr->next)
			return (FAILURE);
		ptr->next->content = content;
		ptr->next->type = type;
	}
	return (SUCCESS);
}
