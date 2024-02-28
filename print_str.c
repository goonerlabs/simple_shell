#include "shell.h"

/**
 * print_str - prints a string
 * @str: string to be printed
 * Return: number of characters printed
 */

int print_str(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
