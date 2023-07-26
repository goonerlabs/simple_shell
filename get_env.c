#include "shell.h"

/**
 * get_env - function the gets the environment variables
 * @name: varible name
 *
 * Return: value
 */

char *get_env(char *name)
{
	char **env = environ, *sign_position = NULL;

	if (name == NULL || *name == '\0')
		return (NULL);

	for (; *env != NULL; env++)
	{
		if (_strncmp(name, *env, _strlen(name)) == 0)
		{
			sign_position = _strchr(*env, '=');
			if (sign_position != NULL)
				return (sign_position + 1);
		}
	}

	return (NULL);
}
