#include <unistd.h>
#include "shell.h"
#include <stddef.h>

/**
 * _execve - execute a shell command by checking for file path
 * @path: given file path
 * @arr_command: array of given commands
 * Return -
 */

int _execve(char *path, char **arr_command)
{
	execve(path, arr_command, NULL);
}
