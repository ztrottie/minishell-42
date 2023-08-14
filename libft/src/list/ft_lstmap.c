/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:54:38 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 10:42:19 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;

	if (!lst || !f || !del)
		return (0);
	temp = lst;
	new = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
			ft_lstclear(&temp, del);
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
