#include "shell.h"

/**
 * _get_env_var - gets the value of an environment variable
 * @var: the environment variable
 *
 * Return: value of the environment variable
 */

char *_get_env_var(char *var)
{
	int i = 0, n = 0;

	n = _strlen(var);
	while (environ[i])
	{
		if (_strncmp(environ[i], var, n) == 0)
		{
			return (environ[i] + n + 1);
		}
		i++;
	}
	return (NULL);
}
