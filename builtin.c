#include "shell.h"

int (*get_builtin(char *command))(char **args, char **front)
{
    builtin_t funcs[] = {
        {"env", mshell_env},
        {"exit", mshell_exit},
        {NULL, NULL}};
    int i;
    i = 0;
    while (funcs[i].name)
    {
        if (_strcmp(funcs[i].name, command) == 0)
            break;
        i++;
    }
    return (funcs[i].f);
}

int mshell_exit(char **args, char **front)
{
    int i, len_of_int = 10;
    int num;
    if (args[0])
    {
        if (args[0][0] == '+')
        {
            i = 1;
            len_of_int++;
        }
        for (; args[0][i]; i++)
        {
            if (i <= len_of_int && args[0][i] >= '0' && args[0][i] <= '9')
                num = (num * 10) + (args[0][i] - '0');
        }
    }
    else
    {
        return (END_OF_FILE);
    }
    args--;
    free_args(args, front);
    free_env();
    exit(num);
}