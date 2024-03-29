/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:20:06 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:20:07 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/here_doc.h"

int	init_parsed_line(t_data *data, t_lines *lines, int type)
{
	size_t	len;

	len = parsed_line_len(data, lines, type);
	lines->parsed_line = ft_calloc(len + 2, sizeof(char));
	if (!lines->parsed_line)
		return (print_error("malloc"), FAILURE);
	lines->i_parsed_line = 0;
	return (SUCCESS);
}

static char	*get_parsed_line(t_data *data, int type, char *line)
{
	t_lines	lines;

	lines.line = line;
	lines.i_line = 0;
	if (init_parsed_line(data, &lines, type) <= 0)
		return (NULL);
	if (hd_line_control(data, &lines, type) <= 0)
		return (NULL);
	return (lines.parsed_line);
}

static void	exit_hd(t_hd *hd, char **line, int exit_code)
{
	ft_free(*line);
	ft_free(hd->name);
	if (close(hd->fd) < 0)
		print_error("close");
	close_all(hd->data, false);
	free_all(hd->data, true);
	exit(exit_code);
}

static int	write_valid(t_hd *hd)
{
	struct stat	file_info;

	if (fstat(hd->fd, &file_info) < 0)
		return (FAILURE);
	if (!(file_info.st_mode & S_IWUSR))
	{
		ft_printf_fd(2, "minishell: you revoked the write perm you twat🤡!\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	get_input(t_hd *hd)
{
	char	*line;
	size_t	len;

	sig_handler_c(true);
	line = readline("> ");
	len = ft_strlen(hd->limiter);
	while (!(ft_strlen(line) == len && ft_strncmp(line, hd->limiter, len) == 0))
	{
		if (!line)
			break ;
		line = get_parsed_line(hd->data, hd->type, line);
		if (write_valid(hd) <= 0)
			exit_hd(hd, &line, 0);
		write(hd->fd, line, ft_strlen(line));
		ft_free(line);
		line = readline("> ");
	}
	if (!line)
		exit_hd(hd, &line, 1);
	exit_hd(hd, &line, 0);
	return (SUCCESS);
}
