#include "shell.h"
/**
 * find_path - function that get a command directory path
 * @command: given command
 * Return: a pointer to the path
 */
char *find_path(char *command)
{
	char *command_path = NULL, *copy = NULL, *token =NULL;
	char *delimiter = ":", *full_path = NULL;
	struct stat buffer;
	ssize_t token_length = 0, commandLength = 0;

	command_path = getenv("PATH");
	if (!command_path)
		return (NULL);
	commandLength = _strlen(command_path);
	copy = (char *)_malloc(commandLength);
	_strcpy(copy, command_path);
	token = strtok(copy, delimiter);
	while (token != NULL)
	{
		token_length = _strlen(token);
		full_path = (char *)_malloc(token_length + commandLength + 2);
		if (full_path == NULL)
		{
			free(copy);
			return (NULL);
		}
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		_strcat(full_path, "\0");
		if (stat(full_path, &buffer) == 0)
		{
			free(copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, delimiter);
	}
	free(copy);
	if (stat(command, &buffer) == 0)
	{
		full_path = (char *)_malloc(strlen(command) + 1);
		_strcpy(full_path, command);
		return (full_path);
	}
	return (NULL);
}
