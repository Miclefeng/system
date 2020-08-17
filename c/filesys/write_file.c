#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    int fd = -1;
    ssize_t size = -1;
    char buf[] = "quick brown fox jumps over the lazy dog";
    char filename[] = "test.txt";

    // fd = open(filename, O_RDWR); /*读写方式打开文件*/
    fd = open(filename, O_RDWR | O_TRUNC); /*将文件先清空，再以读写方式打开文件*/
    if (-1 == fd) {
        printf("Open file %s failure, fd : %d\n", filename, fd);
    } else {
        printf("Open file %s success, fd : %d\n", filename, fd);
    }

    size = write(fd, buf, strlen(buf)); /*将数据写入到文件中*/
    printf("write %d bytes to file %s\n", size, filename);

    close(fd);
    return 0;
}
