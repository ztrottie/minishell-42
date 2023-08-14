/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:08:26 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 15:19:56 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (0);
	if (s1[0] == 0)
		return (ft_strdup(s1));
	i = 0;
	while (ft_strchr(set, s1[i]) != 0 && s1[i])
		i++;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[j]) != 0 && s1[j - 1])
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}
/*
int	main(void)
{
	char *ret = ft_strtrim("", "");

	printf("%s", ret);
}*/
