#include "../../include/prompt.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;
	int		i;
	t_data	data;

	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(t_data));
	cpy_env(&data, env);
	pwd();
	i = 0;
	while (i < 10)
	{
		line = readline("minishell> ");
		// parsing(line, &data) == FAILURE
		if (ft_strlen(line) && commands_init(&data, line) == SUCCESS)
			add_history(line);
		i++;
	}
	rl_clear_history();
}
