#include "../../include/prompt.h"

int	main(int argc, char **argv, char **env)
{
	char 	*line;
	int		i;
	t_data	data;
	
	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(t_data));
	cpy_env(&data, env);
	i = 0;
	while (i < 10)
	{
		line = readline("minishell> ");
		parsing(line, &data);
		commands_init(&data, line);
		add_history(line);
		i++;
	}
	rl_clear_history();
}