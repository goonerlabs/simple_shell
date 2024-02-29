#include "shell.h"

/**
 * tokenize_input - splits user input into array or arguments
 * @input: input
 *
 * Return: tokenized input as an array of strings
 */

char **tokenize_input(char *input)
{
	char **toks = NULL, *tok = NULL, *delim = " \t\r\n\a";
	int n = 0;

	toks = malloc(MAX_ARGS_SIZE * sizeof(char *));
	if (!toks)
	{
		perror("./shell: ");
		exit(EXIT_FAILURE);
	}
	tok = _strtok(input, delim);
	while (tok)
	{
		toks[n] = tok;
		n++;
		tok = _strtok(NULL, delim);
	}
	toks[n] = NULL;
	return (toks);
}

