#include "shell.h"

char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);

char *get_args(char *line, int *exe_ret)
{
    (void)exe_ret;
    ssize_t read;
    int n = 0;

    read = _getline(&line, &n, STDIN_FILENO);
    if (read == -1)
    {
        return (NULL);
    }
    line[read - 1] = '\0';
    return (line);
}

int handle_args(int *exe_ret)
{
    int ret = 0, index;
    char **args, *line = NULL, **front;
    line = get_args(line, exe_ret);
    if (!line)
    {
        return (END_OF_FILE);
    }

    args = _strtok(line, " ");
    free(line);

    if (!args)
    {
        return (ret);
    }
    front = args;
    if (args)
    {
        ret = call_args(args, front, exe_ret);
    }
    free(front);
    return (ret);
}

int call_args(char **args, char **front, int *exe_ret)
{
    int ret = 0;
    ret = run_args(args, front, exe_ret);
}

int run_args(char **args, char **front, int *exe_ret)
{
    int i;
    int ret;
    int (*builtin)(char **args, char **front);
    builtin = get_builtin(args[0]);
    if (builtin)
    {
        ret = builtin(args + 1, front);
        if (ret == EXIT)
        {
            *exe_ret = ret;
        }
    }
    else
    {
        *exe_ret = execute(args, front);
        for (i = 0; args[i]; i++)
        {
            free(args[i]);
        }
    }
    hist++;

    return (ret);
}