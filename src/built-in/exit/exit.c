#include "exit.h"

int	ft_exit(int ac, char **av, long long exit_code)
{
	if (ac > 2)
		return (ft_printf_fd("minishell: exit: too many arguments"), 1);
	if (ac == 2)
	{
		if (ft_islonglong(av[1]))
		{
			ft_atoi_l(av[1]);
			exit_code = av[1];
		}
		else
			return (error_code("numeric argument required", 2, data));
	}
	exit((unsigned int8_t)exit_code);
}
