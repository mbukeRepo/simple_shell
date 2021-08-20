#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
pid_t child_pid;
printf("current process id %d\n", getpid());
child_pid = fork();
if (child_pid < 0)
{
printf("an error happened during process creation\n");
}else if (child_pid == 0)
{
printf("child process %d\n", getpid());
// sleep(20);
}
else {
printf("parent process %d\n", getpid());
sleep(30);
}

}
