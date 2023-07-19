#include "../../include/here_doc.h"

size_t	variable_len_control(t_data *data, char *line)
{
	char	*name;
	char	*exit_code;
	size_t	len;

	name = NULL;
	len = 1;
	if (line[len] && line[len] != ' ')
	{
		name = variable_name(line + len);
		if (name)
			len = ft_strlen(env_variable(data, name));
		else if (line[len] == '?')
		{
			exit_code = ft_itoa(data->exit_code);
			if (!exit_code)
				return (0);
			len = ft_strlen(exit_code);
		}
	}
	return (ft_free(name), len);
}

int	init_parsed_line_len(t_lines *lines, char **line)
{
	size_t	len;

	len = ft_strlen(lines->line);
	*line = ft_calloc(len + 1, sizeof(char));
	if (!*line)
		return (FAILURE);
	ft_strlcpy(*line, lines->line, len + 1);
	return (SUCCESS);
}

size_t	parsed_line_len(t_data *data, t_lines *lines, int type)
{
	char	*line;
	size_t	i;

	if (init_parsed_line_len(lines, &line) <= 0)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && type)
			i += variable_len_control(data, line + i);
		else
			i++;
	}
	return (i + 1);
}
