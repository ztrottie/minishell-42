#include "../../include/prompt.h"

int	main(int argc, char **argv, char **env)
{
	//char	*line;
	//int		i = 0;
	t_data	data;
	t_export	export;
	//char *content[10] = {"unset", "PWD", "USER", "HOME", "PATH", NULL};
	char *e_content[10] = {"export", "c=", "c", "c", "c=", NULL};

	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(t_data));
	cpy_env(&data, env);
	export.env = cpy_environement(NULL, data.env);
	//ft_unset(&data, content, &export, false);
//	printf("\n");
//	printf("\n");
	ft_export(e_content, &export, &data);
	//print_env(data.env);
	// i = 0;
	// while (data.env[i])
	// {
	// 	ft_printf("%s\n", data.env);
	// 	i++;
	// }
	// ft_unset(&data, )
	//i = 0;
	// while (1)
	// {
	// 	line = readline("minishell> ");
	// 	if (!line)
	// 		break ;
	// 	parsing(line, &data);
	// 	add_history(line);
	// 	i++;
	// }
	// ft_x2free((void **)data.env);
}
