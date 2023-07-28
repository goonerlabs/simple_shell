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
	if (_strcmp(command[0], "env") == 0)
		return (handle_env(env));
	/**
	 * if (_strcmp(command[0], "alias") == 0)
	 * {
		print_string(args);
		if (command[1] == NULL)
		{
			get_list(alias_list);
			free_memory(alias_list);
			return (0);
		}
		else if (command[1] != NULL)
		{
			token = strtok(command[1], delim);
			token2 = strtok(NULL, delim);
			create_alias(&alias_list, token, token2);
			return (0);
		}
	 * }
	print_string("not");
	 * if (_strcmp(command[0], "cd") == 0)
		return (change_dir(command, env));
	*/

	return (-1);
}
