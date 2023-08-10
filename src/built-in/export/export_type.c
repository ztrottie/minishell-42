#include "export.h"

static int	get_line_add(char *var, char *content, char **line)
{
	bool	complete;
	int		start;
	int		len;

	complete = is_complete(var);
	start = 0;
	while (content[start])
	{
		if ((complete == INVALID && content[start] == '='))
			break ;
		else if (start - 1 > 0 && content[start - 1] == '=')
			break ;
		start++;
	}
	len = ft_strlen(content) - start;
	*line = ft_substr(content, start, len);
	if (!*line)
		return (FAILURE);
	return (SUCCESS);
}

static int	type_add(char **var, char *content)
{
	char *line;
	char *new_var;

	if (get_line_add(*var, content, &line) <= 0)
		return (FAILURE);
	new_var = ft_strjoin(*var, line);
	ft_free(*var);
	*var = new_var;
	return(SUCCESS);
}

static int	type_trunc(char **var, char *content)
{
	ft_free(*var);
	*var = ft_strdup(content);
	if (!*var)
		return (FAILURE);
	return (SUCCESS);
}

int	type_choice(char **var, char *content, int type)
{
	if (type == ADD)
	{
		if (type_add(var, content) <= 0)
			return (FAILURE);
	}
	else if (type == TRUNC)
	{
		if (type_trunc(var, content) <= 0)
			return (FAILURE);
	}
	return (SUCCESS);
}
