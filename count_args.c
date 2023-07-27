#include "shell.h"

/**
 * count_args - count the number of arguments
 * @str: tokenized string
 * Return: number of arguments
 */

int count_args(char *str)
{
	int ac = 0;
	char *tok = NULL, *temp = NULL;

	if (!str)
		return (0);
	temp = malloc(sizeof(char) * (strlen(str) + 1));
	if (!temp)
		exit(EXIT_FAILURE);
	_strcpy(temp, str);

	tok = strtok(temp, " \n");
	if (!tok)
	{
		free(temp);
		exit(EXIT_FAILURE);
	}
	while (tok)
	{
		tok = strtok(NULL, " \n");
		ac++;
	}
	free(temp);
	return (ac);
}
