/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:03:24 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/06 14:31:40 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	main(void)
{
	char *line;
	
	rl_bind_key('\t', rl_complete);
	while (ft_strncmp(line, "exit\0", 5) != 0)
	{
		line = readline("minishell> ");
		parsing(line);
		add_history(line);
	}
}