#include "shell.h"

/**
 * print_string - function that prints out a given string
 * @str: string to be printed
 * Return: onSuccess(1)
*/

int print_string(char *str)
{
	int index = 0;

	while (str[index])
	{
		_putchar(str[index]);
		index++;
	}

	return (1);
}
