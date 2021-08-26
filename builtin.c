#include "shell.h"
/**
 * get_builtin - Matches a command with a corresponding
 *               shellby builtin function.
 * @command: The command to match.
 *
 * Return: A function pointer to the corresponding builtin.
 */
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
{
break;
}
i++;
}
return (funcs[i].f);
}

/**
 * mshell_exit - Causes normal process termination
 *                for the shellby shell.
 * @args: An array of arguments containing the exit value.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If there are no arguments - -3.
 *         If the given exit value is invalid - 2.
 *         O/w - exits with the given status value.
 *
 * Description: Upon returning -3, the program exits back in the main function.
 */
int mshell_exit(char **args, char **front)
{
int i, len_of_int = 10;
int num = 0;
i = 0;
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

args--;
free_args(args, front);
free_env();
exit(num);
}
