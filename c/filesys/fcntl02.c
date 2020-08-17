/*使用fcntl修改文件的状态值*/
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    int flags = -1;
    int fd = -1;
    int accmode = -1;
    char buf[] = "FCNTL";
    char filename[] = "tfcntl.txt";

    fd = open(filename, O_RDWR);
    // printf("FD : %d\n", fd);
    flags = fcntl(fd, F_GETFL, 0); /*获取文件状态*/
    // accmode = flags & O_ACCMODE;
    // printf("%d\n", accmode);
    // printf("%d\n", O_RDWR);

    flags |= O_APPEND; /*增加状态为可追加*/
    flags = fcntl(fd, F_SETFL, &flags); /*将状态写入，同时将文件的偏移量移到文件末尾*/
    if (flags < 0) {
        printf("failure to use fcntl\n");
        return -1;
    }

    printf("Strlen is %d\n", strlen(buf));
    write(fd, buf, strlen(buf)); /*向文件写入数据*/
    close(fd);
    return 0;
}
