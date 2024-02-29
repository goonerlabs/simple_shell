#include "shell.h"

/**
 * _print_environment_vars - prints environment variables
 *
 * Return: void
 */

void _print_environment_vars(void)
{
	int i = 0;

	while (environ[i])
	{
		print_str(environ[i]);
		print_str("\n");
		i++;
	}
}
