#include "shell.h"

char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);
/**
  * get_args - gets command from user input
  * @line: buffer from userinput
  * @exe_ret: value of the last command
  * Return: pointer to the command
  */
char *get_args(char *line, int *exe_ret)
{
(void)exe_ret;
ssize_t read;
size_t n = 0;

read = _getline(&line, &n, STDIN_FILENO);
if (read == -1)
{
return (NULL);
}
line[read - 1] = '\0';
return (line);
}
/**
 * handle_args - Gets, calls, and runs the execution of a command.
 * @exe_ret: The return value of the parent process' last executed command.
 *
 * Return: If an end-of-file is read - END_OF_FILE (-2).
 *         If the input cannot be tokenized - -1.
 *         O/w - The exit value of the last executed command.
 */
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
/**
 * call_args - Partitions operators from commands and calls them.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 * @exe_ret: The return value of the parent process' last executed command.
 *
 * Return: The return value of the last executed command.
 */
int call_args(char **args, char **front, int *exe_ret)
{
int ret = 0;
ret = run_args(args, front, exe_ret);
}

/**
 * run_args - Calls the execution of a command.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 * @exe_ret: The return value of the parent process' last executed command.
 *
 * Return: The return value of the last executed command.
 */
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
