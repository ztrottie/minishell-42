#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"
# include "here_doc.h"

int		commands_separator(t_data *data, t_tokens **tokens);
int		file_add_end(t_files **files, char *name, int fd);
void	files_free(t_files **files);
int		pid_add_end(t_data *data, pid_t pid);
void	free_pid_list(t_data *data);

#endif