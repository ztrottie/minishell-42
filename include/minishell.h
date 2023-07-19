#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../readline/readline.h"
# include "../readline/history.h"
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

# define METACHAR "|<>"

enum REDIRECION
{
	PIPE = 1,
	RED_IN = 2,
	HERE_DOC = 3,
	RED_OUT = 4,
	RED_OUT_APPEND = 5,
};

# define QUOTES -1
# define NONE -200

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

typedef struct s_files
{
	char			*name;
	int				fd;
	int				cmd_index;
	struct s_files	*next;
}	t_files;

typedef struct s_cmds
{
	int		nb;
	char	*name;
	char	**content;
	int		nb_input;
	t_files	*input_fds;
	int		nb_output;
	t_files	*output_fds;
}	t_cmds;

typedef struct s_pid_list
{
	pid_t				pid;
	struct s_pid_list	*next;
}	t_pid_list;

typedef struct s_data
{
	t_cmds		*cmds;
	t_tokens	*tokens;
	char		**env;
	int			nb_pipe;
	int			exit_code;
	t_pid_list	*pid;
}	t_data;


#endif