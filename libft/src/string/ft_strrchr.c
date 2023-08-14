/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:26:42 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 15:19:41 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (const char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
