#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"

# define TOKEN_ERROR "syntax error near unexpected token"
# define CALLOC_ERROR "calloc error"

void	ft_exit(t_data *data, char *error, char *type, bool system);

#endif