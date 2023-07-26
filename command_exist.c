#include "shell.h"

/**
 * command_exist - checks if a shell command is valid
 * @command: command to validate
 * Return: onSuccess(0), else(-1)
 */

int command_exist(char *command)
{
	char *result = NULL;

	result = find_path(command);

	if (result != NULL)
	{
		free(result);
		return (0);
	}
	else
	{
		free(result);
		return (-1);
	}
}
