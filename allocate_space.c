#include "shell.h"

/**
 * allocate_space - alloacates a block of memory on the heap
 * @size: size of the block to allocate
 * Return: pointer to the allocated block of memory
 */

char **allocate_space(int size)
{
	char **p = NULL;

	p = malloc(sizeof(char *) * (size + 1));
	if (p == NULL)
		return (NULL);
	return (p);
}
