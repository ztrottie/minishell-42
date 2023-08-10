#include "../../../include/built_in.h"

int	exit_or_reset(bool fork, int exit_code)
{
	if (fork)
		exit(exit_code);
	else
		return (exit_code);
}