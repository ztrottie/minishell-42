#ifndef HERE_DOC_H
# define HERE_DOC_H

# include "minishell.h"
# include "commands.h"
# include "env.h"

typedef struct	s_lines
{
	char	*line;
	char	*parsed_line;
	size_t	i_line;
	size_t	i_parsed_line;
}	t_lines;

int		here_doc_main(t_data *data, t_files **inputs, char *limiter, int type);
int		get_input(t_data *data, int fd, char *limiter, int type);
size_t	parsed_line_len(t_data *data, t_lines *lines, int type);

#endif