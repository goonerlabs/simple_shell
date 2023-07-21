#include "shell.h"
#include <unistd.h>

/**
 * _putchar - prints the required output
 * @c: given string
 * Return: output onSuccess
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
