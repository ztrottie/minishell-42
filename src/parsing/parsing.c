#include "../../include/parsing.h"

int	parsing(char *line, t_data *data)
{
	size_t	i;
	int		last;
	size_t	count;

	i = 0;
	last = 0;
	count = 0;
	(void)data;
	while (line[i])
	{
		if (is_metachar(line[i]) == last && is_metachar(line[i]) != INVALID)
			count++;
		else
			count = 0;
		if ((is_metachar(line[i]) == 1 && count == 1) || count == 2)
			ft_exit(data, &line[i], TOKEN_ERROR, false);
		last = is_metachar(line[i]);
		i++;
	}
	return (SUCCESS);
}
