#include "shell.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s1: string to search
 * @s2: string to search for
 *
 * Return: pointer to the byte in s1 that matches s2
 */

char *_strpbrk(char *s1, char *s2)
{
	const char *ptr1, *ptr2;

	ptr1 = s1;
	while (*ptr1)
	{
		ptr2 = s2;
		while (*ptr2)
		{
			if (*ptr1 == *ptr2)
				return ((char *)ptr1);
			ptr2++;
		}
		ptr1++;
	}
	return (NULL);
}
