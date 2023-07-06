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
	i = 0;
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
			break ;
		if (ft_strlen(line) > 0)
			parsing(line, &data);
		add_history(line);
		i++;
	}
	ft_x2free((void **)data.env);
	rl_clear_history();
}
