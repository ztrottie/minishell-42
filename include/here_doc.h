#ifndef HERE_DOC_H
# define HERE_DOC_H

# include "minishell.h"
# include "commands.h"
# include "env.h"
# include "parsing.h"

int		here_doc_main(t_data *data, t_files **inputs, char *limiter, int type);
int		get_input(t_data *data, int fd, char *limiter, int type);
size_t	parsed_line_len(t_data *data, t_lines *lines, int type);
int		hd_line_control(t_data *data, t_lines *lines, int type);
int		hd_variable_control(t_data *data, t_lines *lines);
void	hd_basic_control(t_lines *lines);

#endif