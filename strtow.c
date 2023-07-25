#include "shell.h"

/**
 * count - count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count(char *s)
{
	int check, c, w;

	check = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			check = 0;
		else if (check == 0)
		{
			check = 1;
			w++;
		}
	}

	return (w);
}

/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **array_2d, *temp;
	int i, k = 0, len = 0, words, c = 0, start_index, end_index;

	while (*(str + len))
		len++;
	words = count(str);
	if (words == 0)
		return (NULL);

	array_2d = (char **) malloc(sizeof(char *) * (words + 1));
	if (array_2d == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end_index = i;
				temp = (char *) malloc(sizeof(char) * (c + 1));
				if (temp == NULL)
					return (NULL);
				while (start_index < end_index)
					*temp++ = str[start_index++];
				*temp = '\0';
				array_2d[k] = temp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start_index = i;
	}

	array_2d[k] = NULL;

	return (array_2d);
}
