#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"

int		commands_init(t_data *data, t_tokens **tokens);
int		file_add_end(t_files **files, char *name, int fd);
void	files_free(t_files **files);

#endif