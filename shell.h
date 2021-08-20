#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
char *name;
char *_strcpy(char *dest, const char *src);
int _getline(char **lineptr, int *n, FILE *stream);
char **_strtok(char *str, char *del);
int execute(char **, char **);
int handle_args(int *exe_ret);
#endif