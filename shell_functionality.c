#include "shell.h"

/**
 * _shell - simple shell functionality
 * @av : array of arguments
 * Return: 0
 */

int _shell(char **av)
{
	char *args = NULL, **argv = NULL, *delim = " \n", **env = environ;
	int ac = 0;
	size_t size = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_string("$ ");
		if (get_line(&args, &size, STDIN_FILENO) == -1)
		{
			free(args);
			print_string("Shell Exited!\n");
			exit(EXIT_FAILURE);
		}
		ac = count_args(args);
		argv = allocate_space(ac);
		get_args(args, argv, delim);
		special_commands(argv, env, args);

		if (command_exist(argv[0]) == -1)
		{
			free_vector(argv);
			free(argv);
			perror("Error ");
		}
		else
			myfork(argv, args, av);
	}
	free(args);
	return (0);
}
