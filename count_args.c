#include "shell.h"

/**
 * count_args - count the number of arguments
 * @str: tokenized string
 * Return: number of arguments
 */

int count_args(char *str)
{
	int ac = 0;
	char *temp = NULL, *tok = NULL;

	temp = (char *)_malloc(_strlen(str));
	_strcpy(temp, str);
	tok = strtok(temp, " \n");
	if (!tok)
		exit(EXIT_FAILURE);
	while (tok)
	{
		tok = strtok(NULL, " \n");
		ac++;
	}
	free(temp);
	return (ac);
}
