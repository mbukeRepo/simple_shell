# mshell(1)

Version 1.0.1, August 2021


<a name="name"></a>

# Name


mshell - a command line interpreter written in c

<a name="synopsis"></a>

# Synopsis

```

 \f[B]mshell\f[R] [\f[I]filename\f[R]]
```

<a name="description"></a>

# Description


\f[B]mshell\f[R] is a custom shell interpreter that ships with a bunch
of great featu

res that a local shell interpreter doesnot have.
when \f[B]mshell\f[R] is invoked wit

h

<a name="invocation"></a>

### Invocation


\f[B]mshell\f[R] can be both invoked interractively or
non-interractively if invoked with standard input not from terminal, it
can read commands from term inal

if invoked with standard input connected to the terminal, (determined by
isatty) , an interractive shell is opened

Alternatively, if a command line arg is provided, \f[B]mshell\f[R]
treats the first ar g as a file from which to read commands.
The supplied file should contain comman d per line

<a name="environment"></a>

### Environment


Upon invocation, \f[B]mshell\f[R] copies the environment of the parent
process in whic h it was executed.This environment is an array of
name-value strings in format o f NAME=VALUE.

<a name="command-execution"></a>

### Command execution


After receiving command, \f[B]mshell\f[R] tokenizes it into words using
\f[B]\[dq] \[dq]\f[R] as a d elimiter, the first word as the command and
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


\f[B]mshell\f[R] returns the exit status of the last command executed
with zero indica ting success and a non-zero for failure

if command is not found, return 127; if found but not executable return
127

<a name="signals"></a>

### Signals


While running in interractive mode, \f[B]mshell\f[R] ignores keyboard **
ctrl + c ** .
Alternatively, an EOF input will exit program

<a name="variable-replacement"></a>

### Variable replacement


* **\f[B]mshell\f[R] interprets $ character for variable replacement**  
  \f[B]$ENV_VARIABLE\f[R] : ENV_VARIABLE is substituted with its value
  \f[B]$?\f[R] : ?
  is substituted with the return value of the last program
  \f[B]$$\f[R] : $ is substituted the the current process id

<a name="comments"></a>

### Comments


\f[B]mshell\f[R] ignores the all words and characters that preceeded by
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

### \f[B]mshell\f[R] Build in commands


<a name="cd"></a>

### cd


\f[B]usage\f[R] :\f[B]cd\f[R] [DIRECTORY]

changed the current directory to DIRECTORY

if no arg provided the dir will be changed to dir in $HOME

if arg is ** - \f[B], the command is interpreted as \f[R] cd $OLDPWD**
and the new working dir is printed

if arg is ** \[en] \f[B], the command is interpreted as \f[R] cd
$OLDPWD** and the new working dir is not printed

the PWD and OLDPWD env var are updated after changing dir

<a name="alias"></a>

### alias


\f[B]usage\f[R] :\f[B]alias\f[R] [NAME=[\`VALUE'] ...].
Handles aliases

\f[B]alias\f[R] :prints all aliases in form of name-value format

\f[B]alias\f[R] NAME ...:prints aliases NAME and so on, in a
name-value format

\f[B]alias\f[R] NAME=\`VALUE':defines alias NAME

<a name="exit"></a>

### exit


\f[B]usage\f[R] : \f[B]exit\f[R] [STATUS] Exits the shell.
if no status provided it is interpreted as ,\[lq]\f[B]exit\f[R] 0\[rq]

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
