#include "../../include/execution.h"

// static int	open_pipes(t_data *data)
// {
// 	size_t	i;
// 	int		end[2];

// 	i = 0;
// 	while (i < data->nb_pipe)
// 	{
// 		if (pipe(end) < 0)
// 			return (FAILURE);
// 		if (file_add_end(data->cmds[i].output, end[1], NULL, false) \
// 		|| file_add_end(data->cmds[i + 1].input, end[0], NULL, false))
// 			return (FAILURE);
// 		i++;
// 	}
// 	return (SUCCESS);
// }

// static int	std_redirection(t_data *data)
// {
// 	if (data->nb_pipe > 0)
// 		if (open_pipes(data) <= 0)
// 			return (FAILURE);
// 	if (open)
// 	close_all(data);
// 	free_all(data, false);
// }

int	redirection_main(t_data *data, int mode)
{
	// if (mode == STD)
	// {
	// 	if (std_redirection(data) <= 0)
	// 		return (FAILURE);
	// }
	if (mode == ERROR)
		if (error_redirection(data) <= 0)
			return (FAILURE);
	return (SUCCESS);
}
