# include "../../include/here_doc.h"

int	init_parsed_line(t_data *data, t_lines *lines, int type)
{
	size_t	i;

	i = 0;
	while (lines->line)
}

char	*get_parsed_line(t_data *data, int type)
{
	t_lines lines;
	char	*line;

	lines.line = readline("> ");
	if (init_parsed_line(data, &lines, type))
		return (NULL);
	line = ft_strjoin(lines.parse_line, "\n");
	if (!line)
		return (NULL);
	return (ft_free(line), parsed_line);
}

int	get_input(t_data *data, int fd, char *limiter, int type)
{
	char	*line;
	char	*new_limiter;
	size_t	len;

	new_limiter = ft_strjoin(limiter, "\n");
	if (!new_limiter)
		exit(0);
	line = ft_strjoin(readline("> "), "\n");
	len = ft_strlen(new_limiter);
	while (line && ft_strncmp(line, new_limiter, len) != 0)
	{
		write(fd, line, sizeof(char *));
		line = ft_strjoin(readline("> "), "\n");
	}
	exit(0);
}
