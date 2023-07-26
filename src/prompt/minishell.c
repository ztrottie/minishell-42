#include "../../include/prompt.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_data	data;

	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(t_data));
	cpy_env(&data, env);
	while (1)
	{
		data.nb_pipe = 0;
		line = readline("minishell> ");
		if (!line)
			break ;
		if (ft_strlen(line) > 0)
			parsing(line, &data);
		add_history(line);
	}
	free_all(&data, true);
	rl_clear_history();
}
