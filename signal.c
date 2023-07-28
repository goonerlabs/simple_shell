#include "shell.h"

/**
 * signal_handler - exits the shell with CTRL+C
 * @sig: signal
 */

void signal_handler(int sig)
{
	(void)sig;
	print_string("\n");
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
	exit(EXIT_SUCCESS);
}
