#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(void)
{
    int result = -1; /*创建管道结果*/
    int fd[2], nbytes;
    char string[] = "Hello Miclefeng pipe!";
    char readbuffer[80];
    pid_t pid; /*进程的ID*/

    /* 文件描述符，1、用于写，0、用于读 */
    int *write_fd = &fd[1];
    int *read_fd = &fd[0];

    result = pipe(fd);
    if (-1 == result) {
        printf("建立管道失败！\n");
        return -1;
    }

    pid = fork(); /*分叉程序*/
    if (-1 == pid) {
        printf("Fork 进程失败！\n");
        return -1;
    }

    if (0 == pid) {
        /*子进程 关闭读端 写入数据*/
        close(*read_fd);
        result = write(*write_fd, string, strlen(string));
        return 0;
    } else {
        /*父进程 关闭写端 读取数据*/
        close(*write_fd);
        nbytes = read(*read_fd, readbuffer, sizeof(readbuffer));
        printf("收到%d个数据，内容为：%s\n", nbytes, readbuffer);
        return 0;
    }
}
