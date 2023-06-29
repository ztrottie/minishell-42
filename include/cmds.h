#ifndef CMDS_H
# define CMDS_H

# include "minishell.h"
# include "env.h"

typedef struct s_lines
{
	char		*line;
	char		*parsed_line;
	size_t		i_line;
	size_t		i_parsed_line;
}	t_lines;

int		commands_init(t_data *data, char *line);
int		split_command(t_data *data, t_lines *lines);
int		is_metachar(int c);
int		is_operator(char *line, int index);
size_t	nb_metachar(char *line);
int		is_quote(int c);
void	single_quote_control(t_lines *lines);
void	double_quote_control(t_data *data, t_lines *lines);
void	variable_control(t_data *data, t_lines *lines);
void	basic_control(t_lines *lines);
int		check_quotes(t_lines *lines);

#endif