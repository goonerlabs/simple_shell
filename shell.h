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

#define MAX_ARGS_SIZE 1024

extern char **environ;
int _putchar(char c);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
int _strncmp(char *str1, char *str2, int c);
int _strcspn(char *s1, char *s2);
int _atoi(char *s);
char *_strchr(char *s, char c);
int print_str(char *str);
char *get_user_input(void);
char **tokenize_input(char *input);
int _exec(char **args);
int _shell(void);
void signal_callback_func(int sig);
char *_get_env_var(char *var);
char **_get_env_dir(char *p);
char *get_full_path(char *cmd);
void _print_environment_vars(void);

#endif /* SHELL_H */
