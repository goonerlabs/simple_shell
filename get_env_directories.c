#include "shell.h"

/**
 * _get_env_dir - tokenize path to return array of environment directories
 *@p: path to tokenize
 *
 * Return: array of environment directories
 */

char **_get_env_dir(char *p)
{
	char **toks = NULL, *tok = NULL, *delim = ":", *path = p;
	int n = 0;

	toks = malloc(MAX_ARGS_SIZE * sizeof(char *));
	if (!toks)
	{
		return (NULL);
	}
	tok = strtok(path, delim);
	while (tok)
	{
		toks[n] = tok;
		n++;
		tok = strtok(NULL, delim);
	}
	toks[n] = NULL;
	return (toks);
}
