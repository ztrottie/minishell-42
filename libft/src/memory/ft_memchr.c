/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:44:39 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 10:53:37 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	chr;
	unsigned char	*str;

	if (!s)
		return (0);
	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *)str + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	//int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%s", ft_memchr(s, 0, 0));
}*/