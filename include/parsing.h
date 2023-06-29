#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "cmds.h"
# include "error.h"

# define SPECIAL_CHAR "|<>\'\""

typedef struct s_line
{
	char 	*line;
	size_t	i_line;
}	t_line;

int	parsing(char *line, t_data *data);

#endif