#include "../../include/cmds.h"

size_t	parsed_line_size(t_data *data, char *line_read)
{
	size_t	len;

	len = 0;
	len += ft_strlen(line_read);
	len += nb_metachar(line_read);
	len += variable_content_len(data, line_read);
	return (len);
}

int	init_lines(t_data *data, t_lines *lines, char *line_read)
{
	int	len;

	ft_bzero(lines, sizeof(t_lines));
	lines->line = line_read;
	len = parsed_line_size(data, line_read);
	lines->parsed_line = ft_calloc(len, sizeof(char *));
	if (!lines->parsed_line)
		return (FAILURE);
	return (SUCCESS);
}

int	commands_init(t_data *data, char *line_read)
{
	t_lines		lines;

	if (init_lines(data,  &lines, line_read) == FAILURE)
		return (FAILURE);
	if (split_command(data, &lines) == INVALID)
		return (ft_free(lines.parsed_line), FAILURE);
	create_tokens();
	return (SUCCESS);
}
