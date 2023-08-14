#include "exit.h"

int	ft_exit(int ac, char **av, long long exit_code, bool fork)
{
	if (ac > 2)
	{
		return (ft_printf_fd(2, "exit\nminishell: exit: too many arguments\n"), \
		1);
	}
	if (ac == 2)
	{
		if (ft_islonglong(av[1]))
			exit_code = ft_atoi_l(av[1]);
		else
		{
			ft_printf_fd(2, "exit\nminishell: exit: numeric argument required\n");
			exit(255);
		}
	}
	exit_code = (unsigned)(int8_t)exit_code;
	if (fork)
		ft_x2free((void **)av);
	exit(exit_code);
}
