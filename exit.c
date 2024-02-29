#include "shell.h"

/**
 * _exit_shell - implementation of exit builtin
 * @args: argument vector
 * @input: input
 *
 * Return: always 0
 */

int _exit_shell(char **args, char *input)
{
	int status = 0;

	if (args[1])
		status = _atoi(args[1]);
	free(input);
	free(args);
	exit(status);
	return (0);
}
