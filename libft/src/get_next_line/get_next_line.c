/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:11:00 by ztrottie          #+#    #+#             */
/*   Updated: 2023/03/02 16:40:03 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

size_t	ft_find(char *stash, ssize_t nbyte)
{
	size_t	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0' && nbyte < BUFFER_SIZE)
		return (i);
	if (stash[i] == '\n')
		return (i + 1);
	return (0);
}

char	*ft_clean_stash(char *stash, char *line)
{
	char	*new_stash;
	size_t	len_line;
	size_t	len;
	size_t	i;

	len_line = ft_strlen(line);
	len = ft_strlen(stash) + 1;
	new_stash = ft_calloc(len - len_line, sizeof(char));
	i = 0;
	while (i < len - len_line)
	{
		new_stash[i] = stash[len_line + i];
		i++;
	}
	if (*new_stash == 0)
		new_stash = ft_free(new_stash);
	return (stash = ft_free(stash), new_stash);
}

char	*ft_make_line(char *stash, ssize_t nbyte)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = ft_find(stash, nbyte);
	line = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t		nbyte;
	char		*buffer;
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nbyte = BUFFER_SIZE;
	while (nbyte == BUFFER_SIZE && ft_find(stash, nbyte) == 0)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte == -1)
			return (buffer = ft_free(buffer), stash = ft_free(stash), NULL);
		stash = ft_get_strjoin(stash, buffer);
		buffer = ft_get_bzero(buffer, BUFFER_SIZE + 1);
	}
	if (nbyte != 0 || ft_find(stash, nbyte) > 0)
	{
		line = ft_make_line(stash, nbyte);
		return (ft_free(buffer), stash = ft_clean_stash(stash, line), line);
	}
	return (free(stash), free(buffer), NULL);
}
