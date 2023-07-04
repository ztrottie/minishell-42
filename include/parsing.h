#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "error.h"
# include "env.h"

# define LIMITCHAR " <>|"

#define TOKERROR 258

typedef struct s_tokens
{
	int				type;
	char			*content;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_line
{
	char 	*line;
	size_t	i_line;
}	t_line;

int		parsing(char *line, t_data *data);
int		token_add_end(t_tokens **tokens, int type, char *content);
int		token_split(t_data *data, t_tokens **tokens, t_line *line);
int		is_operator(t_line *line);
int		is_metachar(int c);
int		is_redirection(char *line, int len);
int		is_quote(int c);
int		is_limitchar(int c);
int		cpy_line(t_line *line, t_line *tmp_line);
size_t	parsed_content_len(t_data *data, t_line *line);
void	basic_control(t_line *line, t_line *content);
int		string_control(t_data *data, t_tokens **tokens, t_line *line);
void	free_tokens(t_tokens **tokens);
int		tokens_parsing(t_data *data, t_tokens **tokens);
int		variable_control(t_data *data, t_line *line, t_line *content, int quote);

#endif