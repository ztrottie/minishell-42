#include "unset.h"

int	parse_var(char *var, int *exit_code)
{
	int	i;

	i = 0;
	if (!ft_isalpha(var[0]) && var[0] != '_')
	{
		*exit_code = 1;
		ft_printf_fd(2, "minishell: export: `%s : not a valid identifier\n", var);
		return (INVALID);
	}
	while (var[i])
	{
		if (var[i] == '=' || (var[i] == '+' && var[i + 1] == '='))
			break ;
		if ((!ft_isalnum(var[i]) && var[i] != '_') || var[i] == ' ')
		{
			*exit_code = 1;
			ft_printf_fd(2, "minishell: export: `%s : not a valid identifier\n", var);
			return (INVALID);
		}
		i++;
	}
	return (SUCCESS);
}

int	exit_or_reset(bool fork, int exit_code)
{
	if (fork)
		exit(exit_code);
	else
		return (exit_code);
}
