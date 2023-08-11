#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "env.h"
# include "commands.h"

# define LIMITCHAR " <>|"

# define TOKERROR 258

typedef struct s_line
{
	char	*line;
	size_t	i_line;
}	t_line;

int		parsing(char *line, t_data *data);
int		token_add_end(t_tokens **tokens, int type, char *content);
int		token_split(t_data *data, t_tokens **tokens, t_lines *lines);
int		is_operator(t_lines *lines);
int		is_metachar(int c);
int		is_redirection(char *line, int len);
int		is_quote(int c);
int		is_limitchar(int c);
int		cpy_line(t_lines *lines, t_line *tmp_line);
size_t	parsed_content_len(t_data *data, t_lines *lines);
void	basic_control(t_lines *lines);
int		string_control(t_data *data, t_tokens **tokens, t_lines *lines);
void	free_tokens(t_tokens **tokens, bool flag);
int		variable_control(t_data *data, t_lines *lines, int quote);

#endif