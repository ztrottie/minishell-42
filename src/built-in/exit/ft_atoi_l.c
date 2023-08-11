#include "exit.h"

long long	ft_atoi_l(const char *str)
{
	long long	nb;
	int			sign;
	int			i;

	nb = 0;
	i = 0;
	sign = 1;
	if (str[i] && str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * sign);
}
