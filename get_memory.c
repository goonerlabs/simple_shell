#include "shell.h"

/**
 * get_memory - function that allocates memory
 * @bufs: given size
 * Return: pointer to memory
 */

char *get_memory(int bufs)
{
	char *buf = NULL;

	buf = (char *)_malloc(bufs);
	return (buf);
}

/**
 * reallocate_memory - function that allocates memory
 * @buf: variable to reallocate memory to
 * @bufs: given size
 * Return: pointer to reallocated emory
 */

char *reallocate_memory(char *buf, int bufs)
{
	char *result = NULL;
	int i = 0;
	
	i = _strlen(buf);

	result = (char *)_realloc(buf, i, bufs);
	if (result == NULL)
	{
		perror("Unable to allocate memory");
		return (NULL);
	}
	return (result);
}
