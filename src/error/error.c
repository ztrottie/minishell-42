#include "../../include/error.h"

void print_error(char *cause)
{
	ft_printf_fd(2, "minishell: ");
	perror(cause);
	ft_printf_fd(2, "\n");
}
