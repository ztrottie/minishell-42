/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:03:24 by ztrottie          #+#    #+#             */
/*   Updated: 2023/06/20 01:15:09 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/prompt.h"

int	main(void)
{
	char 	*line;
	t_data	data;
	
	ft_bzero(&data, sizeof(t_data));
	while (ft_strncmp(line, "exit\0", 5) != 0)
	{
		line = readline("minishell> ");
		commands_init(&data, line);
		add_history(line);
	}
	clear_history();
}