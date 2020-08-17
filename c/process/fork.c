#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;

    pid = fork();

    if (-1 == pid) {
        printf("进程创建失败！\n");
        return -1;
    } else if (pid == 0) {
        printf("%d\n", getppid());
        printf("子进程，fork返回值: %d, ID : %d,父进程ID : %d\n", pid, getpid(), getppid());
        return 0;
    } else {
        printf("父进程，fork返回值: %d, ID : %d,父进程ID : %d\n", pid, getpid(), getppid());
        return 0;
    }

}
