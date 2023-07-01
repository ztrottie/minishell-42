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
		line = "allo";
		if (!line)
			break ;
		if (ft_strlen(line) && commands_init(&data, line))
			add_history(line);
		ft_free(line);
		i++;
	}
	ft_x2free((void **)data.env);
	rl_clear_history();
}
