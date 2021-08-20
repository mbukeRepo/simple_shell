# mshell(1)

Version 1.0.1, August 2021

<a name="name"></a>

# Name

mshell - a command line interpreter written in c

<a name="synopsis"></a>

# Synopsis

```

 mshell [\f[I]filename]
```

<a name="description"></a>

# Description

mshell is a custom shell interpreter that ships with a bunch
of great featu

res that a local shell interpreter doesnot have.
when mshell is invoked wit

h

<a name="invocation"></a>

### Invocation

mshell can be both invoked interractively or
non-interractively if invoked with standard input not from terminal, it
can read commands from term inal

if invoked with standard input connected to the terminal, (determined by
isatty) , an interractive shell is opened

Alternatively, if a command line arg is provided, mshell
treats the first ar g as a file from which to read commands.
The supplied file should contain comman d per line

<a name="environment"></a>

### Environment

Upon invocation, mshell copies the environment of the parent
process in whic h it was executed.This environment is an array of
name-value strings in format o f NAME=VALUE.

<a name="command-execution"></a>

### Command execution

After receiving command, mshell tokenizes it into words using
\[dq] \[dq] as a d elimiter, the first word as the command and
others are arguments.It then proceed s with the following action:

: if the first character of the command is neither a slash () nor dot
(.), the shell searches for it in the list of builtins.

: if the first char of the command is not ( &nbsp;or .
or builtins), the shell searc hes for it in the PATH environment var for
dir containing an executable file by that name

: if the search is successful it then executes the program in a separate
executi on environment

<a name="exit-status"></a>

### Exit status

mshell returns the exit status of the last command executed
with zero indica ting success and a non-zero for failure

if command is not found, return 127; if found but not executable return
127

<a name="signals"></a>

### Signals

While running in interractive mode, mshell ignores keyboard **
ctrl + c ** .
Alternatively, an EOF input will exit program

<a name="variable-replacement"></a>

### Variable replacement

- **mshell interprets $ character for variable replacement**  
  $ENV_VARIABLE : ENV_VARIABLE is substituted with its value
  $? : ?
  is substituted with the return value of the last program
  $$ : $ is substituted the the current process id

<a name="comments"></a>

### Comments

mshell ignores the all words and characters that preceeded by
a # char

<a name="operators"></a>

### Operators

: ; -Command separator: command separated by this operator are
processed sequen tially

: && - and logical operator: command1 && command2 - command2 is
executed if and only if, command1 returns a 0 exit status

: || - or logical operator: command1 || command2 - command2 is
executed even if command1 failed

<a name="fbmshellfr-build-in-commands"></a>

### mshell Build in commands

<a name="cd"></a>

### cd

usage :cd [DIRECTORY]

changed the current directory to DIRECTORY

if no arg provided the dir will be changed to dir in $HOME

if arg is ** - , the command is interpreted as cd $OLDPWD**
and the new working dir is printed

if arg is ** \[en] , the command is interpreted as cd
$OLDPWD** and the new working dir is not printed

the PWD and OLDPWD env var are updated after changing dir

<a name="alias"></a>

### alias

usage :alias [NAME=[\`VALUE'] ...].
Handles aliases

alias :prints all aliases in form of name-value format

alias NAME ...:prints aliases NAME and so on, in a
name-value format

alias NAME=\`VALUE':defines alias NAME

<a name="exit"></a>

### exit

usage : exit [STATUS] Exits the shell.
if no status provided it is interpreted as ,\[lq]exit 0\[rq]

<a name="env"></a>

### env

prints current environment

<a name="setenv"></a>

### setenv

initializes new variable , or modifies the existing one.

<a name="unsetenv"></a>

### unsetenv

Removes the environment variable

<a name="authors"></a>

# Authors

mbuke prince and collins wilson.
