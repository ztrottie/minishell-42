#include "../../include/prompt.h"

static int	init_data(int argc, char **argv, char **env, t_data *data)
{
	(void)argc;
	(void)argv;
	ft_bzero(data, sizeof(t_data));
	if (cpy_env(data, env) <= 0)
		return (FAILURE);
	return (SUCCESS);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_data	data;

	if (init_data(argc, argv, env, &data) <= 0)
		return (FAILURE);
	while (1)
	{
		data.nb_pipe = 0;
		sig_handler_p(false, true);
		line = readline("minishell> ");
		sig_handler_p(false, false);
		if (!line)
			break ;
		if (ft_strlen(line) > 0)
		{
			if (parsing(line, &data) == SUCCESS)
				if (redirection_main(&data, STD))
					exec_main(&data);
		}
		add_history(line);
		free_all(&data, false);
	}
	free_all(&data, true);
	ft_printf("exit\n");
	rl_clear_history();
}
