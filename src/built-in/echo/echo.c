#include "echo.h"

static int	check_if_option(char **content)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (content[i])
	{
		j = 1;
		if (ft_strncmp("-n", content[i], 2) == 0)
		{
			while (content[i][j] == 'n')
				j++;
			if (!content[i][j])
				count++;
			else
				return (count);
		}
		i++;
	}
	return (count);
}

int	echo(char **content)
{
	int	i;

	i = check_if_option(content) + 1;
	while (content[i])
	{
		printf("%s", content[i]);
		if (content[i + 1])
			printf(" ");
		i++;
	}
	if (check_if_option(content) == 0)
		printf("\n");
	return (SUCCESS);
}
