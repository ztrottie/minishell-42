#include "../../include/here_doc.h"

size_t	variable_len_control(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{

	}
}

int	init_parsed_line_len(t_lines *lines, char **line)
{
	size_t	len;

	len = ft_strlen(lines->line);
	*line = ft_calloc(len + 1, sizeof(char));
	if (!*line)
		return (FAILURE);
	ft_strlcpy(*line, lines->line, len);
	reuturn (SUCCESS);
}

size_t	parsed_line_len(t_data *data, t_lines *lines)
{
	char	*line;
	size_t	i;

	if (init_parsed_line_len(lines, &line) <= 0)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
			i += variable_len_control(line + i);
		else
			i++;
	}
	return (i);
}
