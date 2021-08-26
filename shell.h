#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#define END_OF_FILE -2
#define EXIT -3
char *name;
extern char **environ;
int hist;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
    char *dir;
    struct list_s *next;
} list_t;

/**
 * struct builtin_s - a new struct type defining builtin commands
 * @name: name of built in command
 * @f: function pointer to builtin command's function
 */
typedef struct builtin_s
{
    char *name;
    int (*f)(char **argv, char **front);
} builtin_t;



int execute(char **, char **);
int handle_args(int *exe_ret);
int (*get_builtin(char *command))(char **args, char **front);

/* built-ins */
int mshell_env(char **args, char __attribute__((__unused__)) * *front);
int mshell_exit(char **args, char **front);
/* errors */
char *_itoa(int num);
int create_error(char **args, int err);
char *error_127(char **args);
char *error_126(char **args);

/* string functions */
char **_strtok(char *str, char *del);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char **_copy_env();
void free_env(void);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncat(char *dest, const char *src, size_t n);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* linked list funcs */
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

/* helpers */
void free_args(char **args, char **front);
/* environment */
char **_getenv(char *var);

/* locating a command */
char *get_location(char *command);
#endif