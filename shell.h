#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>


int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
void _print_str(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strchr(char *s, char c);
char *_strpbrk(char *s, char *accept);
unsigned int _strspn(char *s, char *accept);
char *_strstr(char *haystack, char *needle)
char **strtow(char *str)
#endif /* SHELL_H */
