/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:47:13 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 15:20:09 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
int	main(void)
{
	char *str = "01234";
	size_t size = 10;
	char *ret = ft_substr(str, 10, size);

	printf("%s\n", ret);
}*/