#include "shell.h"
#include <stdlib.h>

/**
 * _malloc - allocates memory to a variable
 * @size: variable size
 * Return: pointer to memory
 */

void *_malloc(int size)
{
	void *p = NULL;

	p = malloc(sizeof(char) * (size + 1));
	if (p == NULL)
	{
		print_string("Memory allocation failed. Exiting...\n");
		exit(1);
	}

	return (p);
}
