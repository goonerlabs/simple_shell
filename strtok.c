#include "shell.h"

/**
 * _strtok - tokenizes a string
 * @s: string to tokenize
 * @d: delimiter string
 *
 * Return: pointer to the token
 */

char *_strtok(char *s, char *d)
{
	static char *ptr;
	char *res = NULL;

	if (s != NULL)
		ptr = s;
	if (ptr == NULL)
		return (NULL);
	ptr += _strspn(ptr, d);
	if (*ptr == '\0')
		return (NULL);
	res = ptr;
	ptr = _strpbrk(ptr, d);
	if (ptr != NULL)
	{
		*ptr = '\0';
		ptr++;
	}
	return (res);
}
