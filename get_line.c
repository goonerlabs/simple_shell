#include "shell.h"

/**
 * get_line - function that acts like getline function
 * @lineptr: agrguments parsed
 * @n: init size is 0
 * @fd: file descriptor
 * Return: 0 on succes, otherwise -1
 */

ssize_t get_line(char **lineptr, size_t *n, int fd)
{
	static int defaultSize = 120;
	ssize_t bufSize = 0, bytes = 0;
	char *buffer = NULL, c = 0;

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		bufSize = defaultSize;
		buffer = get_memory(bufSize);
		*lineptr = buffer;
		*n = bufSize;
	}
	else
	{
		buffer = *lineptr;
		bufSize = *n;
	}
	while (read(fd, &c, 1) > 0)
	{
		buffer[bytes] = c;
		bytes++;
		if (bytes >= bufSize)
		{
			bufSize = bufSize * 2;
			buffer = reallocate_memory(buffer, bufSize);
			*lineptr = buffer;
			*n = bufSize;
		}
		if (c == '\n')
			break;
	}
	buffer[bytes] = '\0';
	if (bytes == 0 && c == '\0')
	{
		free(buffer);
		*lineptr = NULL;
		return (-1);
	}
	return (bytes);
}
