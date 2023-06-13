/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:42:04 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/13 17:42:48 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

char *space_remover(char *str)
{
	int		len;
	int		i;
	int		start;
	int		end;

	i = 0;
	len = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		i++;
	start = i;
	i = 0;
	while (ft_isspace(str[len - i]))
		i++;
	end = len - i;
	ft_printf("len:%d start:%d end:%d\n", len, start, end);
	return (NULL);
}

char **create_tokens(char *line)
{
	return (ft_split(line, '|'));
}

void	parsing(char *line)
{
	int	i;
	char **str;
	
	str = create_tokens(line);
	i = 0;
	while (str[i])
	{
		space_remover(str[i]);
		ft_printf("[%d]|%s| len : %d\n", i, str[i], ft_x2strlen(str));
		i++;
	}
}
