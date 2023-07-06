#include "../../include/prompt.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;
	int		i = 0;
	t_data	data;
	char *content[] = {"unset", "PWD", "USER"};

	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(t_data));
	cpy_env(&data, env);
	while (data.env[i])
	{
		ft_printf("%s\n", data.env[i]);
		i++;
	}
	ft_unset(&data, content);
	ft_printf("\n");
	ft_printf("\n");
	i = 0;
	while (data.env[i])
	{
		ft_printf("%s\n", data.env[i]);
		i++;
	}
	i = 0;
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
			break ;
		parsing(line, &data);
		add_history(line);
		i++;
	}
	ft_x2free((void **)data.env);
	rl_clear_history();
}
