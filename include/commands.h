#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"
# include "here_doc.h"

int		tokens_parsing(t_data *data, t_tokens **tokens);
int		pid_add_end(t_pid_list **pid_list, pid_t pid);
void	free_pid_list(t_data *data);
int		wait_pid_list(t_pid_list **pid);
void	free_red_list(t_red **red_list);
int		red_add_end(t_red **red_list, int type, char *content);


#endif