#include "../../include/prompt.h"

int	main(int argc, char **argv, char **env)
{
	char 	*line;
	t_data	data;
	
	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(t_data));
	cpy_env(&data, env);
	while (1)
	{
		line = readline("minishell> ");
		commands_init(&data, line);
		add_history(line);
	}
	clear_history();
}