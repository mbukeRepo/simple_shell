#include "shell.h"

char **_copy_env()
{
    char **new_environ;
    size_t size;
    int index;
    for (size = 0; environ[size]; size++)
    {
    }
    new_environ = malloc(sizeof(char *) * (size + 1));
    if (!new_environ)
    {
        return (NULL);
    }
    index = 0;
    while (environ[index])
    {
        new_environ[index] = malloc(_strlen(environ[index]) + 1);
        if (!new_environ[index])
        {
            for (index--; index >= 0; index--)
                free(new_environ[index]);
            free(new_environ);
            return (NULL);
        }
        _strcpy(new_environ[index], environ[index]);
        index++;
    }
    new_environ[index] = NULL;
    return (new_environ);
}

/**
 * free_env - Frees the the environment copy.
 */
void free_env(void)
{
    int index;

    for (index = 0; environ[index]; index++)
        free(environ[index]);
    free(environ);
}