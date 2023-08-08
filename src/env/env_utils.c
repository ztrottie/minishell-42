#include "../../include/env.h"

int	is_valid_var(int c)
{
	if (ft_isalnum(c) || c == '_')
		return (VALID);
	return (INVALID);
}
