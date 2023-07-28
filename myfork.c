#include "shell.h"

/**
 * myfork - calls fork command
 * @argv: argument vector
 * @args: arguments
 * @av: shell argument vector
 *
 * Return: onSuccess(1), otherwise(0)
 */

int myfork(char **argv, char *args, char **av)
{
			pid_t child_id;

			if (args == NULL)
				return (0);

			child_id = fork();
			if (child_id == -1)
			{
				free(args);
				free_vector(argv);
				perror("./hsh ");
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
			return (1);
}
