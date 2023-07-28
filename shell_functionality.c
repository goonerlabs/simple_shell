#include "shell.h"

/**
 * _shell - simple shell functionality
 * @av : array of arguments
 * Return: 1
 */

int _shell(char **av)
{
	char *args = NULL, **argv = NULL, *delim = " \n", **env = environ;
	int ac = 0, sig = 1;
	size_t size = 0;

	signal(SIGINT, signal_handler);

	while (sig)
	{
		sig = isatty(STDIN_FILENO);

		if (sig == 1)
			print_string("$ ");

		if (get_line(&args, &size, STDIN_FILENO) == -1)
		{
			free(args);
			return (0);
		}
		ac = count_args(args);
		argv = allocate_space(ac);
		if (argv == NULL)
		{
			perror("./hsh ");
			return (0);
		}
		get_args(args, argv, delim);
		special_commands(argv, env, args);

		if (command_exist(argv[0]) == -1)
		{
			free_vector(argv);
			free(args);
			perror("./hsh ");
		}
		else
			sig = myfork(argv, args, av);
	}
	free(args);
	return (1);
}
