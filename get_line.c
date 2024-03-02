#include "shell.h"
/**
 *_getline - gets input from stdin
 *@ptr: the buffer
 *@n: the size of the buffer
 *@fd: the file descriptor
 *
 * Return: user input or NULL
 */

int _getline(char **ptr, size_t *n, int fd)
{
	static size_t cs = 120;
	char *buffer = NULL, str;
	size_t  s = 0, b = 0;

	if (ptr == NULL || n == NULL || fd < 0)
		return (-1);
	if (*ptr == NULL  || *n == 0)
	{
		s = cs;
		buffer = malloc(s);
		if (buffer == NULL)
			return (-1);
		*ptr = buffer;
		*n = s;
	}
	else
	{
		buffer = *ptr;
		s = *n;
	}
	while (read(fd, &str, 1) > 0)
	{
		buffer[b++] = str;
		if (b >= s)
		{
			buffer = __realloc(buffer, s * 2);
			*ptr = buffer;
			*n = s;
		}
		if (str == '\n')
			break;
	}
	buffer[b] = '\0';
	if (b == 0 && str == '\0')
	{
		free(buffer);
		*ptr = NULL;
		return (-1);
	}
	return (b);
}
