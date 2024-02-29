#include "shell.h"

/**
 * get_user_input - gets input from stdin
 *
 * Return: user input or NULL
 */

char *get_user_input(void)
{
	char *str = NULL;
	int characters;
	size_t n = 0;

	characters = _getline(&str, &n, STDIN_FILENO);
	if (characters == -1)
	{
		free(str);
		return (NULL);
	}
	characters--;
	if (str[characters] == '\n')
		str[characters] = '\0';
	return (str);
}
