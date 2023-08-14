/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:18:49 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/14 17:18:50 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

int	parse_var(char *var, int *exit_code)
{
	int	i;

	i = 0;
	if (!ft_isalpha(var[0]) && var[0] != '_')
	{
		*exit_code = 1;
		ft_printf_fd(2, "minishell: export: `%s : not a valid identifier\n", \
		var);
		return (INVALID);
	}
	while (var[i])
	{
		if (var[i] == '=' || (var[i] == '+' && var[i + 1] == '='))
			break ;
		if ((!ft_isalnum(var[i]) && var[i] != '_') || var[i] == ' ')
		{
			*exit_code = 1;
			ft_printf_fd(2, "minishell: export: `%s : not a valid identifier\n", \
			var);
			return (INVALID);
		}
		i++;
	}
	return (SUCCESS);
}
