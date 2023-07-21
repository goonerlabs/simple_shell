#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <aio.h>

/**
 * startShell - program entry function;
 * @argv - array of arguments
 *
 * Return: onSuccess(1)
*/

int shellStart(char **argv)
{
	char *line_buff = NULL;
	size_t n = 0, line_count = 0, index = 0;

	while (line_count != -1)
	{
		_printf("$: ");
		line_count = getline(&line_buff, &n, stdin);
		if (line_count == -1)
			perror(argv[0]);

		_printf(line_buff);
	}
	free(line_buff);

	return (1);
}
