#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "here_doc.h"
# include "commands.h"

int		free_files(t_files **files);
int		file_add_end(t_files **files, int fd, char *name, bool here_doc);
int		redirection_main(t_data *data, int mode);
int		close_all(t_data *data);
void	free_all(t_data *data, bool all);
int		error_redirection(t_data *data);
int		convert_redirection(t_data *data);
int		output_redirection_choice(t_red *red, t_files *file);
int		input_redirection_choice(t_data *data, t_red *red, t_files *file);

#endif