#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "built_in.h"

int		exec_main(t_data *data);
int		pid_add_end(t_pid_list **pid_list, pid_t pid);
void	free_pid_list(t_data *data);
int		wait_pid_list(t_pid_list **pid);

#endif