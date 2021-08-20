#include "shell.h"
void assign_lineptr(char **lineptr, int *n, char *buffer, int input)
{
if (*lineptr == NULL)
{
    if (input > 120)
    {
        *n = input;
    }else
    {
        *n = 120;
    }
    *lineptr = buffer;
}else if (*n < input)
{
if (input > 120)
{
*n = input;
}else {
    *n = 120;
}
}else {
_strcpy(*lineptr, buffer);
free(buffer);
}
}
int _getline(char **lineptr, int *n, FILE *stream)
{
int input;
char c = 'x', *buffer;
int ret;
int r;
input = 0;
buffer = malloc(sizeof(char) * 120);
if (!buffer)
{
free(buffer);
return (-1);
}
while (c != '\n')
{
r = read(STDIN_FILENO, &c, 1);
// failed to read or end of file (empty file)
if (r == -1 || (r == 0 && input == 0))
{
free(buffer);
return (-1);
}
// end of file 
if (r == 0 && input != 0)
{
input++;
break;
}
// reallocate buffer for large input
// ... to be writter
buffer[input] = c;
input++;
}
buffer[input] = '\0';
assign_lineptr(lineptr, n, buffer, input);
ret = input;
return (ret);
}