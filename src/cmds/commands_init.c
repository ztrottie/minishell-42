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

void	commands_init(t_data *data, char *line_read)
{
	int		len;
	t_lines	lines;
	char	**parse_line;
	size_t	word;

	ft_bzero(&lines, sizeof(t_lines));
	lines.line = line_read;
	len = parsed_line_size(data, line_read);
	ft_printf("%d\n", len);
	lines.parsed_line = ft_calloc(len, sizeof(char *));
	split_command(data, &lines);
	ft_printf("%s\n", lines.parsed_line);
	parse_line = ft_split(lines.parsed_line, 29);
	word = ft_word_count(lines.parsed_line, 29);
	for (size_t i = 0; i < word; i++)
		ft_printf("|%s|\n", parse_line[i]);
}
