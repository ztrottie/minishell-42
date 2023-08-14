/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:38:26 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/15 09:14:56 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

void	*ft_x2free(void **p)
{
	int	i;

	if (p)
	{
		i = -1;
		while (p[++i])
			ft_free(p[i]);
		ft_free(p);
	}
	return (NULL);
}

void	*ft_free(void *p)
{
	if (p)
		free(p);
	return (NULL);
}
