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
	pid_t child_id;
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
			child_id = fork();
			if (child_id == -1)
			{
				free(args);
				free_vector(argv);
				free(argv);
				exit(EXIT_FAILURE);
			}
			else if(child_id == 0)
			{
				execute(av, argv, args, 0);
				free(args);
				free_vector(argv);
				free(argv);
			}
			else
			{
				wait(NULL);
				free_vector(argv);
				free(argv);
			}
		/*}*/
	}
	free(args);
	return (0);
}
