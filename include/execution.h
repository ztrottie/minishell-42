#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "built_in.h"
# include "redirection.h"
# include "env.h"

# define COMMAND_NOT_FOUND -30

enum e_type
{
	GIVEN = 21,
	COMMAND = 22,
	BUILTIN = 23,
};

int		exec_main(t_data *data);
int		pid_add_end(t_pid_list **pid_list, pid_t pid);
void	free_pid_list(t_data *data);
int		wait_pid_list(t_data *data);
int		exec_nofork(t_data *data);
int		check_builtin_nofork(t_data *data);
int		child_process(t_data *data, int cmd_nb);
int		std_exec(t_data *data);
int		get_in_out(t_cmds *cmds);
int		get_cmd_path(t_data *data, int cmd_nb, int type, char **path);
void	path_error(t_data *data, int cmd_nb, int type);

#endif