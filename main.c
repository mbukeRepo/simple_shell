#include "shell.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute(char **userinput, char **front)
{
    int status, flag, ret = 0;
    pid_t child_pid;
    int exec_res;
    char *command = userinput[0];

    if (command[0] != '.' && command[0] != '/')
    {
        // do stuff
    }

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Error child:");
        return (-1);
    }

    else if (child_pid == 0)
    {
        execve(command, userinput, NULL);
    }
    else
    {
        wait(&status);
        printf("Successful executed \n");
    }
    //     int i = 0;
    //     while (i < 3)
    //     {
    //         printf("%s\n", userinput[i]);
    //         i++;
    //     }
    return (ret);
}

int main(void)
{
    char *lineptr = NULL;
    char **userinput;
    char *newline = "\n", *prompt = "$ ";
    int ret = 0, retn;

    int *exe_ret = &retn;

    // handle input from terminal

    // handle input from file

    // handle input from interractive shell

    while (1)
    {
        write(STDOUT_FILENO, prompt, 2);
        ret = handle_args(exe_ret);
    }

    // char *argv[] = {"/bin/l", "-l", "/usr/", NULL};
    // // printing prompt

    // write(STDOUT_FILENO, "$ ", 2);
    // // getting command from user

    // _getline(&lineptr, &n, STDIN_FILENO);
    // userinput = _strtok(lineptr, " ");

    // // executing command
    // execute(argv);

    // free(lineptr);
    return (0);
}
