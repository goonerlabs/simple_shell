#ifndef SHELL_H
#define SHELL_H

int shellStart(char **argv);
int _putchar(char c);
int _printf(char *str);
int _execve(char *path, char **arr_command);
char** _strtok(char *str);

#endif
