#include "cd.h"

int main(int ac, char **av, char **env)
{
	cd(ac, av, &env);
	return (0);
}