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
# define SINGLE_QUOTE 1
# define DOUBLE_QUOTE 2
# define VALID 1
# define INVALID 0
# define SUCCESS 0
# define FAILURE -1

typedef struct s_files
{
	char			*name;
	int				fd;
	int				cmd_nb;
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

typedef struct s_data
{
	t_cmds	*cmds;
	int		**pipe;
	int		nb_cmds;
	char	**env;
	t_files	*input_fds;
	t_files	*output_fds;
}	t_data;

#endif