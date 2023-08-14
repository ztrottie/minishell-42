/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:51:14 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/09 22:00:07 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"
#include "../../includes/memory.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!ptr)
		return (0);
	ptr = ft_memcpy(ptr, s1, ft_strlen(s1));
	return (ptr);
}
