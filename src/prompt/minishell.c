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
		line = readline("minishell> ");
		if (!line)
			break ;
		if (ft_strlen(line) > 0)
		{
			if (parsing(line, &data) == SUCCESS)
				redirection_main(&data, STD);
		}
		add_history(line);
		free_all(&data, false);
	}
	free_all(&data, true);
	rl_clear_history();
}
