#include "export.h"

int	check_type(char *content, int index)
{
	if (content[index] == '=')
		return (TRUNC);
	else if (content[index] == '+')
		return (ADD);
	return (INVALID);
}

int	is_complete(char *var)
{
	size_t	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			return (VALID);
		i++;
	}
	return (INVALID);
}
