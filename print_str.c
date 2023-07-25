#include "shell.h"

/**
 * _print_str - prints a string, followed by a new line
 * @s: string to print
 * Return: void
 */

void _print_str(char *s)
{
	if (*s == '\0')
	{
		return;
	}
	_putchar(*s);
	_print_str(s + 1);
}
