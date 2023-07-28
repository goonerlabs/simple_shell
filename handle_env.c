#include "shell.h"

/**
 * handle_env - function that handles env command
 * @env: environment variable
 *
 * Return: onSuccess(1)
 */

int handle_env(char **env)
{
	int index = 0;

	for (; env[index]; index++)
		printf("%s\n", env[index]);

	return (1);
}
