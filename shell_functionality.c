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
		if (getline(&args, &size, stdin) == -1)
		{
			free(args);
			perror("Shell Exited!");
			exit(EXIT_FAILURE);
		}
		ac = count_args(args);
		argv = allocate_space(ac);
		get_args(args, argv, delim);
		/**if (command_exist(argv[0], argv) != 0)
		{
			free(args);
			exit(EXIT_FAILURE);
		}
		else
		{*/
			special_commands(argv, env, args);
			myfork(argv, args, av);
		/*}*/
	}
	free(args);
	return (0);
}
