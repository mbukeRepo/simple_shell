#include "shell.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int sig)
{
    char *newline = "\n$ ";
    (void)sig;
    signal(SIGINT, sig_handler);
    write(STDOUT_FILENO, newline, 3);
}

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

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Error child:");
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
    //     int i = 0;
    //     while (i < 3)
    //     {
    //         printf("%s\n", userinput[i]);
    //         i++;
    //     }
    return (ret);
}

int main(int argc, char **argv)
{
    char *lineptr = NULL;

    char **userinput;
    char *newline = "\n", *prompt = "$ ";
    int ret = 0, retn;

    int *exe_ret = &retn;
    name = argv[0];
    printf("%s\n", name);
    hist = 1;
    // handle ctrl + d

    signal(SIGINT, sig_handler);

    // COPYING ENVIRONMENT VARIABLES

    environ = _copy_env();
    if (!environ)
    {
        exit(-100);
    }

    // handle input from terminal

    // handle input from file

    // handle input from interractive shell

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

    // char *argv[] = {"/bin/l", "-l", "/usr/", NULL};
    // // printing prompt

    // write(STDOUT_FILENO, "$ ", 2);
    // // getting command from user

    // _getline(&lineptr, &n, STDIN_FILENO);
    // userinput = _strtok(lineptr, " ");

    // // executing command
    // execute(argv);

    // free(lineptr);
    free_env();
    return (0);
}
