#include "shell.h"

int length(char **arg);

/**
 * main - starts the simple shell
 * @argc: argument count
 * @av: argument vector
 *
 * Return: 0
 */

int main(int argc, char **av)
{
	(void) argc;
	_shell(av);
	return (0);
}
