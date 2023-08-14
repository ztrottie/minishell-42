/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:16:35 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 15:14:47 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != (const char)c && s[i])
		i++;
	if ((const char)c == s[i])
		return ((char *)s + i);
	return (0);
}
/*
int	main(void)
{
	char s[] = "tripouille";
	printf("%s\n", ft_strchr(s, 't' + 257));
	printf("%s\n", strchr(s, 't' + 257));
}*/