#include "../../include/prompt.h"

int	main(int argc, char **argv, char **env)
{
	char 	*line;
	t_data	data;
	char	cwd[256];

	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(t_data));
	cpy_env(&data, env);
	printf("%s\n", getcwd(cwd, sizeof(cwd)));
	pwd(&data);
	while (1)
	{
		line = readline("minishell> ");
		commands_init(&data, line);
		add_history(line);
	}
	clear_history();
	return (0);
}
