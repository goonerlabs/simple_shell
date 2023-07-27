#include "shell.h"

/**
 * myfork - calls fork command
 * @argv: argument vector
 * @args: arguments
 * @av: shell argument vector
 *
 * Return: void
 */

void myfork(char **argv, char *args, char **av)
{
			pid_t child_id;

			child_id = fork();
			if (child_id == -1)
			{
				free(args);
				free_vector(argv);
				exit(EXIT_FAILURE);
			}
			else if (child_id == 0)
			{
				execute(av, argv, args, 0);
				free(args);
				free_vector(argv);
			}
			else
			{
				wait(NULL);
				free_vector(argv);
			}
}
