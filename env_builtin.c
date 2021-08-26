#include "shell.h"
/**
  * mshell_env - prints environment variables on the list
  * @args: arguments to the command
  * @front: command
  * Return: return 0 for success or non-zero for failure
  */
int mshell_env(char **args, char __attribute__((__unused__)) **front)
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
