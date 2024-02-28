#include "shell.h"

/**
 * _exec - executes a command
 * @args: the command and it's arguments
 *
 * Return: 0 on success, 1 on failure
 */

int _exec(char **args)
{
	pid_t pid;

	if (args[0] == NULL)
	{
		perror("hsh");
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
