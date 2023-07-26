#include "shell.h"

/**
 * get_args - gets arguments from tokenized string
 * @args: tokenized string
 * @argv: array of arguments
 * @delim: the delimeter
 *
 * Return: array size
 */

int get_args(char *args, char **argv, char *delim)
{
	char *tok = NULL;
	char *temp = NULL;
	int i = 0;

	temp = (char *)_malloc(_strlen(args));
	_strcpy(temp, args);

	tok = strtok(temp, delim);
	while (tok)
	{
		argv[i] = (char *)_malloc(_strlen(tok));
		_strcpy(argv[i], tok);

		i++;
		tok = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(temp);
	return (i);
}
