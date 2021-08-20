#include "shell.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute(char **userinput)
{
    int status;
    pid_t child_pid;
    int exec_res;
    child_pid = fork();
    if (child_pid == -1)
    {
        printf("creation of process failed");
    }
    else if (child_pid == 0)
    {
        exec_res = execve(userinput[0], userinput, NULL);
        if (exec_res == -1)
        {
            printf("Command failed\n");
        }
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
}

int main(void)
{
    char *lineptr = NULL;
    char **userinput;
    int n = 0;
    char *argv[] = {"/bin/l", "-l", "/usr/", NULL};
    // printing prompt

    write(STDOUT_FILENO, "$ ", 2);
    // getting command from user

    _getline(&lineptr, &n, STDIN_FILENO);
    userinput = _strtok(lineptr, " ");

    // executing command
    execute(argv);

    free(lineptr);
    return (0);
}
