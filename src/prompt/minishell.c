#include "../../include/prompt.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;
	int		i;
	t_data	data;
	char	cwd[256];

	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(t_data));
	cpy_env(&data, env);
	printf("%s\n", getcwd(cwd, sizeof(cwd)));
	pwd(&data);
	while (1)
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
