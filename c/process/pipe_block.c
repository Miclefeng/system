#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 1024
#define WRITELEN (128 * K)

int main(void)
{
    int result = -1; /*创建管道结果*/
    int fd[2], nbytes; /*文件描述符，字符个数*/
    pid_t pid; /*PID*/
    char string[WRITELEN] = "Hello Miclefeng pipe";
    char readbuffer[10 * K]; /*读缓冲区*/
    int *write_fd = &fd[1]; /*文件描述符1，用于写*/
    int *read_fd = &fd[0]; /*文件描述符0，用于读*/

    result = pipe(fd);
    if (-1 == result) {
        printf("建立管道失败\n");
        return -1;
    }

    pid = fork(); /*分叉程序*/
    if (-1 == pid) {
        printf("Fork 进程失败\n");
        return -1;
    }

    if (0 == pid) {
        /*子进程，关闭读管道*/
        close(*read_fd);
        int write_size = WRITELEN;
        result = 0;

        while (write_size >= 0) {
            result = write(*write_fd, string, write_size); /*写入管道数据*/
            printf("\n=====> 写入 %d 个数据 <=====\n\n", result);
            if (result > 0) {
                write_size -= result; /*写入的长度*/
                printf("写入%d个数据，剩余%d个数据\n", result, write_size);
            } else {
                sleep(10);
                break;
            }
        }
        return 0;
    } else {
        /*父进程，关闭写管道*/
        close(*write_fd);
        while (1) {
            nbytes = read(*read_fd, readbuffer, sizeof(readbuffer)); /*读取数据*/
            if (nbytes <= 0) {
                printf("没有数据写入了\n");
                break;
            }
            printf("接收到%d个数据，内容为：'%s'\n", nbytes, readbuffer);
        }
        return 0;
    }
}
