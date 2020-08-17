#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char *args[] = {"/bin/ls", NULL};

    printf("系统分配的进程ID ： %d\n", getpid());
    if (execve("/bin/ls", args, NULL) < 0)
        printf("创建进程失败！\n");

    return 0;
}
