#include "shell.h"
/**
 * free_args - Frees up memory taken by args.
 * @args: A null-terminated double pointer containing commands/arguments.
 * @front: A double pointer to the beginning of args.
 */
void free_args(char **args, char **front)
{
size_t i;

for (i = 0; args[i] || args[i + 1]; i++)
free(args[i]);

free(front);
}
