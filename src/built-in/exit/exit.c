#include "../../../include/built_in.h"

static void	error_code(char *message, int status, t_data *data)
{
	data->exit_code = 0;
	ft_printf("%s\n", message);
	data->exit_code = status;
}

void	ft_exit(t_data *data, t_cmds *cmds)
{
	if (cmds->content[0])
	{
		if (ft_isint(cmds->content[0]))
		{
			if (cmds->content[1])
				return (error_code("Too many arguments", 2, data));
			if (data->exit_code > 255 || data->exit_code < 0)
				data->exit_code = 255;
		}
		else
			return (error_code("numeric argument required", 2, data));
	}
	exit(data->exit_code);
}
