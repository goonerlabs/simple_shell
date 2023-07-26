#include "shell.h"

int length(char **arg);

/**
 * main - starts the simple shell
 * @argc: argument count
 * @av: argument vector
 * @env: environment vector
 * Return: 0
 */

int main(int argc, char **av)
{
	char **argv = NULL, *delim = " ", *args = NULL;
	int len = 0;

	if (argc == 1)
		_shell(av);
	else
	{
		argv = allocate_space(argc);
		len = get_len(av);
		args = malloc(sizeof(char) * (len + 1));
		if (!args)
			exit(EXIT_FAILURE);
		tokenize(args, av);
		get_args(args, argv, delim);
		execute(av, argv, args, 1);

		free(args);
		exit(98);
	}
	free(argv);

	return (0);
}
