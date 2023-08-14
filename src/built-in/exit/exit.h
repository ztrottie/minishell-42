#ifndef EXIT_H
# define EXIT_H

# include "../../../include/minishell.h"

int			ft_exit(int ac, char **av, long long exit_code, bool fork);
int			ft_islonglong(char *str);
long long	ft_atoi_l(const char *str);

#endif