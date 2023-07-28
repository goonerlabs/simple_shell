#include "shell.h"

/**
 * special_commands - function that checks for some specific commands
 * @command: command to check
 * @env: the environment variables
 * @args: user entry
 * Return: onError(-1)
 */

int special_commands(char **command, char **env, char *args)
{
	if (_strcmp(command[0], "exit") == 0)
		return (__exit(command, args));
	if (_strcmp(command[0], "env") == 1)
		return (handle_env(env));
	/**
	 * if (_strcmp(command[0], "cd") == 0)
		return (change_dir(command, env));
	*/

	return (-1);
}
