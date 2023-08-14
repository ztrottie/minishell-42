/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:28:01 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 15:19:27 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nee_len;

	i = 0;
	nee_len = ft_strlen(needle);
	if (nee_len == 0)
		return ((char *)haystack);
	while (haystack[i] && (i + nee_len) <= len)
	{
		if (ft_strncmp(haystack + i, needle, nee_len) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char *s1 = "AAAAAAAAAAAAA";
    size_t max = strlen(s1);
    char *i1 = strnstr(s1, s1, max); 
	char *i2 = ft_strnstr(s1, s1, max);
	printf("%s", i2);
}*/
