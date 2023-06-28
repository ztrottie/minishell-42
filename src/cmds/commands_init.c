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

int	commands_init(t_data *data, char *line_read)
{
	int		len;
	t_lines	lines;

	ft_bzero(&lines, sizeof(t_lines));
	lines.line = line_read;
	len = parsed_line_size(data, line_read);
	lines.parsed_line = ft_calloc(len, sizeof(char *));
	if (!lines.parsed_line)
		return (FAILURE);
	if (split_command(data, &lines) == INVALID)
		return (ft_free(lines.parsed_line), INVALID);
	char	**parse_line = ft_split(lines.parsed_line, 29);
	size_t	word = ft_word_count(lines.parsed_line, 29);
	for (size_t i = 0; i < word; i++)
		ft_printf("|%s|\n", parse_line[i]);
	return (ft_free(lines.parsed_line), SUCCESS);
}
