#include "shell.h"
int mshell_env(char **args, char __attribute__((__unused__)) * *front)
{
    int index;
    char nc = '\n';
    if (!environ)
        return (-1);
    for (index = 0; environ[index]; index++)
    {
        write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
        write(STDOUT_FILENO, &nc, 1);
    }
    (void)args;
    return (0);
}