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

char	*get_parsed_line(t_data *data, int type)
{
	t_lines lines;

	lines.line = readline("> ");
	lines.i_line = 0;
	if (init_parsed_line(data, &lines, type) <= 0)
		return (NULL);
	if (hd_line_control(data, &lines, type) <= 0)
		return (NULL);
	return (lines.parsed_line);
}

int	get_input(t_data *data, int fd, char *limiter, int type)
{
	char	*line;
	char	*new_limiter;
	size_t	len;

	
	new_limiter = ft_strjoin(limiter, "\n");
	if (!new_limiter)
		exit(0);
	len = ft_strlen(new_limiter);
	line = get_parsed_line(data, type);
	while (line && ft_strncmp(line, new_limiter, len) != 0)
	{
		write(fd, line, ft_strlen(line));
		line = get_parsed_line(data, type);
	}
	exit(0);
}
