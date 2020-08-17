/*打开文件示例*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    /*文件描述符声明*/
    int fd = -1;
    /*打开的文件名*/
    char filename[] = "test.txt";

    /*读写方式打开文件*/
    fd = open(filename, O_RDWR);
    if (-1 == fd) {
        printf("Open file %s failure!, fd : %d\n", filename, fd);
    } else {
        printf("Open file %s success!, fd : %d\n", filename, fd);
    }

    return 0;
}
