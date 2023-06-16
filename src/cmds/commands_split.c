/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:45:13 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/16 17:08:07 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cmds.h"

size_t	token_count(char const *s)
{
	size_t	i;
	size_t	count;
	int		trigger;

	i = 0;
	trigger = 1;
	count = 0;
	while (i <= ft_strlen(s))
	{
		if ((ft_isspace(s[i]) || s[i] == 0) && trigger == 0)
		{
			count++;
			trigger = 1;
		}
		else if (is_metachar(s[i]))
		{
			if (s[i + 1] && is_metachar(s[i + 1]))
				i++;
			count++;
		}
		else if (s[i] == '"')
		{
			i++;
			while (s[i] != '"')
				i++;
			count++;
		}
		else if (s[i] == 39)
		{
			i++;
			while (s[i] != 39)
				i++;
			count++;
		}
		else if (!ft_isspace(s[i]) && trigger == 1)
			trigger = 0;
		i++;
	}
	return (count);
}

char **split_command(char *line)
{
	printf("%zu\n", token_count(line));
	return (NULL);
}
