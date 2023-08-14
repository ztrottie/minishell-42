/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:29:51 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 15:16:46 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"
#include "../../includes/memory.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	size_t		len1;
	size_t		len2;
	size_t		i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (0);
	ptr = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!ptr)
		return (0);
	while (i < len1)
		ptr[i++] = *s1++;
	while (i <= (len1 + len2))
		ptr[i++] = *s2++;
	return (ptr);
}
/*
int	main(void)
{
	char *s1 = "where is my ";
	char *s2 = "malloc ???";

	printf("%s\n", ft_strjoin(s1, s2));
}*/
