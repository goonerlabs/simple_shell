#include "shell.h"

/**
 * _exec - executes a command
 * @args: the command and it's arguments
 *
 * Return: 1 success, 0 fail
 */

int _exec(char **args)
{
	pid_t pid;
	int child_status;
	char *cmd = args[0];

	if (args[0] == NULL)
	{
		perror("hsh");
		return (0);
	}
	pid = fork();
	if (pid == 0)
	{
		if (cmd[0] != '/' && cmd[0] != '.')
			cmd = get_full_path(cmd);
		if (cmd == NULL)
		{
			perror("hsh");
			return (0);
		}
		if (execve(cmd, args, NULL) == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&child_status);
	}
	return (1);
}
