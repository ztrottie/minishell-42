#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"

int		commands_separator(t_data *data, t_tokens **tokens);
int		file_add_end(t_files **files, char *name, int fd);
void	files_free(t_files **files);
int		pid_add_end(t_data *Data, pid_t pid);
void	free_pid_list(t_pid_list **pid_list);
int		here_doc_main(t_data *data, t_files **inputs, char *limiter, int type);

#endif