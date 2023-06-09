#include "../../include/parsing.h"

int	cpy_line(t_line *line, t_line *tmp_line)
{
	size_t	len;

	len = ft_strlen(line->line + line->i_line) + 1;
	tmp_line->line = ft_calloc(len + 1, sizeof(char));
	if (!tmp_line->line)
		return (FAILURE);
	ft_strlcpy(tmp_line->line, line->line + line->i_line, len);
	tmp_line->i_line = 0;
	return (SUCCESS);
}
