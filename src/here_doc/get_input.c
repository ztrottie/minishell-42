# include "../../include/here_doc.h"

int	init_parsed_line(t_data *data, t_lines *lines, int type)
{
	size_t	len;

	len = parsed_line_len(data, lines, type);
	lines->parsed_line = ft_calloc(len + 1, sizeof(char));
	if (!lines->parsed_line)
		return (FAILURE);
	lines->i_parsed_line = 0;
	return (SUCCESS);
}

static char	*get_parsed_line(t_data *data, int type, char *line)
{
	t_lines lines;

	lines.line = line;
	lines.i_line = 0;
	if (init_parsed_line(data, &lines, type) <= 0)
		return (NULL);
	if (hd_line_control(data, &lines, type) <= 0)
		return (NULL);
	return (lines.parsed_line);
}

static void	exit_hd(t_hd *hd, char **line)
{
	ft_free(*line);
	ft_free(hd->name);
	close(hd->fd);
	close_all(hd->data);
	free_all(hd->data, true);
	exit(0);
}

static int	write_valid(t_hd *hd)
{
	struct stat	file_stat;

	if (fstat(hd->fd, &file_stat) < 0)
		return (FAILURE);
	if (file_stat.st_mode != 0100644)
	{
		ft_printf_fd(2, "minishell: you just chmod your here_doc🤡!\n");
		return (FAILURE);
	}
	else
	{
		if (access(hd->name, F_OK) < 0)
		{
			ft_printf_fd(2, "minihsell: you just deleted your here_doc🖕!\n");
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	get_input(t_hd *hd)
{
	char	*line;
	size_t	len;

	line = readline("> ");
	len = ft_strlen(line);
	if (len == 0)
		len = ft_strlen(hd->limiter);
	while (ft_strncmp(line, hd->limiter, len) != 0)
	{
		line = get_parsed_line(hd->data, hd->type, line);
		if (write_valid(hd) <= 0)
			exit_hd(hd, &line);
		write(hd->fd, line, ft_strlen(line));
		write(hd->fd, "\n", 1);
		ft_free(line);
		line = readline("> ");
	}
	exit_hd(hd, &line);
	return (SUCCESS);
}
