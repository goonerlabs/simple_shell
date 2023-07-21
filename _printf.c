#include "shell.h"
#include <stddef.h>

/**
 * _printf - function that prints out a given string
 * @str: string to be printed
 * Return: onSuccess(1)
*/

int _printf(char *str)
{
	int index = 0;

	while (str[index])
	{
		_putchar(str[index]);
		index++;
	}

	return (1);
}
