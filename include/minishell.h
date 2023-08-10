#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../readline/readline.h"
# include "../readline/history.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>

# define METACHAR "|<>"

enum e_token_types
{
	QUOTES = -1,
	PIPE = 1,
	RED_IN = 2,
	HERE_DOC = 3,
	RED_OUT = 4,
	RED_OUT_APPEND = 5,
};

enum e_mode
{
	STD = 1,
	ERROR = 2,
};

# define SINGLE_QUOTE 1
# define DOUBLE_QUOTE 2

# define VALID 1
# define INVALID 0

# define SUCCESS 1
# define FAILURE -1

typedef struct s_tokens
{
	int				type;
	char			*content;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_red
{
	int				type;
	int				cont_type;
	char			*content;
	struct s_red	*next;
}	t_red;

typedef struct	s_files
{
	int				fd;
	char			*name;
	bool			here_doc;
	bool			input;
	struct s_files	*next;
}	t_files;

typedef struct s_cmds
{
	int		nb;
	char	*name;
	char	**content;
	t_red	*red;
	t_files	*input;
	t_files	*output;
}	t_cmds;

typedef struct s_pid_list
{
	pid_t				pid;
	struct s_pid_list	*next;
}	t_pid_list;

typedef struct	s_lines
{
	char	*line;
	char	*parsed_line;
	size_t	i_line;
	size_t	i_parsed_line;
	int		prev_type;
}	t_lines;

typedef struct s_export
{
	char	**env;
	int		exit_code;
	int		env_i;
}	t_export;

typedef struct s_data
{
	t_cmds		*cmds;
	bool		token_error;
	char		**env;
	size_t		nb_pipe;
	int			exit_code;
	struct stat	info_last_hd;
	t_pid_list	*pid;
	t_export	*export;
}	t_data;

#endif