/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:20:37 by ztrottie          #+#    #+#             */
/*   Updated: 2023/08/15 13:31:49 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/prompt.h"

extern int	g_exit_code;

static int	init_data(int argc, char **argv, char **env, t_data *data)
{
	(void)argc;
	(void)argv;
	ft_bzero(data, sizeof(t_data));
	if (cpy_env(data, env) <= 0)
		return (FAILURE);
	data->pwd = ft_calloc(3, sizeof(char *));
	if (!data->pwd)
		return (FAILURE);
	data->pwd[0] = ft_strdup("pwd");
	data->pwd[1] = getcwd(NULL, 0);
	return (SUCCESS);
}

static int	run_minishell(t_data *data)
{
	char	*line;

	data->nb_pipe = 0;
	sig_handler_p(false, true);
	line = readline("minishell> ");
	if (g_exit_code > 0)
	{
		data->exit_code = 1;
		g_exit_code = 0;
	}
	sig_handler_p(false, false);
	if (!line)
		return (INVALID);
	if (ft_strlen(line) > 0)
	{
		if (parsing(line, data) == SUCCESS)
			if (redirection_main(data, STD) == SUCCESS)
				exec_main(data);
	}
	add_history(line);
	free_all(data, false);
	return (VALID);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (init_data(argc, argv, env, &data) <= 0)
		return (FAILURE);
	while (1)
	{
		if (run_minishell(&data) == INVALID)
			break ;
	}
	free_all(&data, true);
	ft_printf("exit\n");
	rl_clear_history();
}
