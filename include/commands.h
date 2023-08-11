#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"
# include "redirection.h"
# include "error.h"

int		init_commands(t_data *data, t_tokens **tokens);
int		expected_token(t_data *data, t_tokens *tokens, bool start);
int		pid_add_end(t_pid_list **pid_list, pid_t pid);
void	free_pid_list(t_data *data);
void	free_red_list(t_red **red_list);
int		red_add_end(t_red **red_list, int type, char *content, int cont_type);
int		init_cmds_content(t_data *data, t_tokens **tokens);
int		find_next_red(bool input, t_red *red);

#endif