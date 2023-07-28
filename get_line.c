#include "shell.h"

/**
 * get_line - function that acts like getline function
 * @strptr: agrguments parsed
 * @size: init size is 0
 * @fdesc: file descriptor
 * Return: 0 on succes, otherwise -1
 */

ssize_t get_line(char **strptr, size_t *size, int fdesc)
{
	static size_t defaultBufferSize = 120;
	ssize_t bufferSize = 0, bytes = 0;
	char *buffer = NULL;
	char buf = 0;

	if (strptr == NULL || size == NULL)
		return (-1);
	if (*strptr == NULL || *size == 0)
	{
		bufferSize = defaultBufferSize;
		buffer = (char *)_malloc(bufferSize);
		*strptr = buffer;
		*size = bufferSize;
	}
	else
	{
		buffer = *strptr;
		bufferSize = *size;
	}
	while (read(fdesc, &buf, 1) > 0)
	{
		buffer[bytes] = buf;
		bytes++;
		if (bytes >= bufferSize)
		{
			buffer = reallocate_memory(buffer, (bufferSize * 2));
			*strptr = buffer;
			*size = bufferSize;
		}
		if (buf == '\n')
			break;
	}
	buffer[bytes] = '\0';
	if (bytes == 0 && buf == '\0')
	{
		free(buffer);
		*strptr = NULL;
		return (-1);
	}
	return (bytes);
}
