#include "shell.h"

/**
 * __exit - exits the shell
 * @av: the arguments vector
 * @env: the environment vector
 * Return: void
 */

int __exit(char **av, char *args)
{
	int stat_code = 0;

	if (av[1] != NULL)
	{
		stat_code = _atoi(av[1]);
		free_vector(av);
		free(args);
		exit(stat_code);
	}
	free_vector(av);
	free(av);
	free(args);
	exit(stat_code);

	return (0);
}


