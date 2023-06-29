#include "../../include/cmds.h"

void	basic_control(t_lines *lines)
{
	lines->parsed_line[lines->i_parsed_line] = lines->line[lines->i_line];
	lines->i_parsed_line++;
	lines->i_line++;
}

int	is_operator(char *line, int	index)
{
	int	metachar_index;

	if (!line)
		return (0);
	metachar_index = is_metachar(line[index]);
	if (metachar_index > 0)
	{
		if (line[index + 1] && is_metachar(line[index + 1]) == metachar_index)
			return (2);
		return (1);
	}
	return (0);
}

size_t	nb_metachar(char *line)
{
	size_t	i;
	size_t	count;
	int		metachar_index;

	i = 0;
	count = 0;
	while (line[i])
	{
		metachar_index = is_metachar(line[i]);
		if (metachar_index > 0)
			count++;
		if (line[i + 1] && metachar_index == is_metachar(line[i + 1]))
			i++;
		i++;
	}
	return (count);
}

int	is_quote(int c)
{
	if (c == 34)
		return (DOUBLE_QUOTE);
	if (c == 39)
		return (SINGLE_QUOTE);
	return (INVALID);
}

int	is_metachar(int c)
{
	int	i;

	i = 0;
	while (METACHAR[i])
	{
		if (METACHAR[i] == c)
			return (i + 1);
		i++;
	}
	return (INVALID);
}
