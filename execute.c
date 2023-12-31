#include "shell.h"

/**
 * execute - executes a command
 * @av: arguments to main
 * @args: argument from getline
 * @argv: arguments to program
 * @i: argument position
 *
 * Return: 0 if succesful and 1 otherwise
 */

int execute(char **av, char **argv, char *args, int i)
{
	char *full_path = NULL;

	(void)av;
	full_path = find_path(argv[i]);
	if (execve(full_path, argv, NULL) == -1)
	{
		free(args);
		free_vector(argv);
		free(full_path);
		perror("./hsh ");
		return (1);
	}
	free(full_path);
	return (0);
}
