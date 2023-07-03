#include "../../include/parsing.h"

int	is_redirection(char *line, int len)
{
	if (len == 2)
	{
		if (ft_strncmp(line, "<<", len) == 0)
			return (HERE_DOC);
		if (ft_strncmp(line, ">>", len) == 0)
			return (RED_OUT_APPEND);
	}
	else
	{
		if (ft_strncmp(line, "<", len) == 0)
			return (RED_IN);
		if (ft_strncmp(line, ">", len) == 0)
			return (RED_OUT);
		if (ft_strncmp(line, "|", len) == 0)
			return (PIPE);
	}
	return (0);
}

int	is_operator(t_line *line)
{
	int	metachar_index;

	metachar_index = is_metachar(line->line[line->i_line]);
	if (metachar_index > 0)
	{
		if (metachar_index != PIPE && \
		is_metachar(line->line[line->i_line + 1]) == metachar_index)
			return (2);
		return (1);
	}
	return (INVALID);
}

int	is_quote(int c)
{
	if (c == '\'')
		return (SINGLE_QUOTE);
	if (c == '"')
		return (DOUBLE_QUOTE);
	return (INVALID);
}

int	is_metachar(int c)
{
	size_t	i;

	i = 0;
	while (METACHAR[i])
	{
		if (METACHAR[i] == c)
			return (i + 1);
		i++;
	}
	return (INVALID);
}

int	is_limitchar(int c)
{
	size_t	i;

	i = 0;
	while (LIMITCHAR[i])
	{
		if (LIMITCHAR[i] == c)
			return (VALID);
		i++;
	}
	return (INVALID);
}
