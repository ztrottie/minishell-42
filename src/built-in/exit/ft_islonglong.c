#include "exit.h"

int	ft_islonglong(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	if (str[i] == '-' && str[i + 1] != '\0' && i < len)
		i++;
	while (i < len)
	{
		if (ft_isdigit(str[i]) == 0)
			return (INVALID);
		i++;
	}
	if (len > 20)
		return (INVALID);
	if (len == 20 && ft_li_atoi(str) < INT_MIN)
		return (INVALID);
	if (len == 19 && ft_li_atoi(str) > INT_MAX)
		return (INVALID);
	return (VALID);
}
