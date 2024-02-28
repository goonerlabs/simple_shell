#include "shell.h"

/**
 * signal_callback_func - handles SIGINT signal
 * @sig: signal number
 *
 * Return: void
 */

void signal_callback_func(int __attribute__((unused)) sig)
{
	print_str("\n($) ");
	fflush(stdout);
}
