/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:50:10 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 10:42:24 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	if (!lst)
		return (0);
	temp = lst;
	i = 0;
	while (temp != 0)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
