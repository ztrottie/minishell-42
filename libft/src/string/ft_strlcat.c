/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:35:03 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 15:17:30 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	j;

	j = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	while (src[j] && (dst_len + j) < (dstsize - 1))
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = 0;
	return (dst_len + src_len);
}
