#include "shell.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * sig_handler - Prints a new prompt upon a signal.
 * @sig: The signal.
 */
void sig_handler(int sig)
{
char *newline = "\n$ ";
(void)sig;
signal(SIGINT, sig_handler);
write(STDOUT_FILENO, newline, 3);
}
/**
 * execute - Executes a command in a child process.
 * @userinput: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - a corresponding error code.
 *         O/w - The exit value of the last executed command.
 */
int execute(char **userinput, char **front)
{
int status, ret = 0;
pid_t child_pid;
char *command = userinput[0];
(void) front;
(void) userinput;
if (command[0] != '.' && command[0] != '/')
{
command = get_location(command);
}
if (!command || access(command, F_OK) == -1)
{
if (errno == EACCES)
{
ret = create_error(userinput, 126);
}
else
{
ret = create_error(userinput, 127);
}
}
else
{
child_pid = fork();
if (child_pid == -1)
{
return (-1);
}
else if (child_pid == 0)
{
execve(command, userinput, environ);
if (errno == EACCES)
{
ret = create_error(userinput, 126);
}
}
else
{
wait(&status);
}
}
return (ret);
}
/**
 * main - Runs a simple UNIX command interpreter.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: The return value of the last executed command.
 */
int main(int argc, char **argv)
{

char *newline = "\n", *prompt = "$ ";
int ret = 0, retn;

int *exe_ret = &retn;

(void) argc;
name = argv[0];

hist = 1;
signal(SIGINT, sig_handler);
environ = _copy_env();
if (!environ)
{
exit(-100);
}
while (1)
{
write(STDOUT_FILENO, prompt, 2);
ret = handle_args(exe_ret);
if (ret == END_OF_FILE || ret == EXIT)
{
if (ret == END_OF_FILE)
{
write(STDOUT_FILENO, newline, 1);
}
free_env();
exit(*exe_ret);
}
}

free_env();
return (0);
}
