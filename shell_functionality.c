#include "shell.h"

void sigint_handler(void);
/**
 * sigint_handler - exits the shell with CTRL+C
 */

void sigint_handler(void)
{
	fflush(stdout);
	print_string("/hsh: Quitting shell\n");
	exit(EXIT_FAILURE);
}

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

	signal(SIGINT, sigint_handler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_string("$ ");
		if (get_line(&args, &size, STDIN_FILENO) == -1)
		{
			free(args);
			exit(EXIT_SUCCESS);
		}
		ac = count_args(args);
		argv = allocate_space(ac);
		get_args(args, argv, delim);
		special_commands(argv, env, args);

		if (command_exist(argv[0]) == -1)
		{
			free_vector(argv);
			free(argv);
			print_string(av[0]);
			print_string(": No such file or directory\n");
		}
		else
			myfork(argv, args, av);
	}
	free(args);
	return (0);
}
