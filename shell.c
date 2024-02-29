#include "shell.h"

/**
 * _shell - handles all simple shell commands
 *
 * Return: 0 on success
 */


int _shell(void)
{
	char *input = NULL, **args = NULL;
	int repl = 1;

	signal(SIGINT, signal_callback_func);
	while (repl)
	{
		repl = isatty(STDIN_FILENO);
		if (repl == 1)
			print_str("($) ");
		input = get_user_input();
		if (!input)
			return (0);
		if (_strcmp(input, "exit") == 0)
		{
			free(input);
			return (0);
		}
		args = tokenize_input(input);
		if (!args)
		{
			free(input);
			free(args);
			continue;
		}
		_exec(args);
		free(input);
		free(args);
	}
	return (0);
}
