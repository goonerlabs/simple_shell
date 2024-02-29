#include "shell.h"

/**
 * __realloc - reallocates memory
 * @ptr: pointer to memory
 * @size: size
 *
 * Return: pointer to new memory
 */

char *__realloc(char *ptr, int size)
{
	char *res = NULL;
	int i;

	i = _strlen(ptr);
	res = (char *) _realloc(ptr, i, size);
	if (res == NULL)
		return (NULL);
	return (res);
}
