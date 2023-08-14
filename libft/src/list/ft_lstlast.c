/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:05:17 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 10:42:16 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	temp = lst;
	while (i < ft_lstsize(lst) - 1)
	{
		i++;
		temp = temp->next;
	}
	return (temp);
}
