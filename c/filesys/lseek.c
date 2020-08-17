#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd = -1;
    ssize_t size = -1;
    off_t offset = -1;

    char buf1[] = "01234567";
    char buf2[] = "ABCDEFGH";
    char filename[] = "hole.txt";
    int len = 8;

    fd = open(filename, O_RDWR | O_CREAT | S_IRWXU);
    if (-1 == fd) {
        printf("Open file %s failure, fd : %d\n", filename, fd);
    } else {
        printf("Open file %s success, fd : %d\n", filename, fd);
    }

    size = write(fd, buf1, len); /*将buf1中的数据写入到文件*/
    if (size != len) {
        return -1;
    }

    offset = lseek(fd, 32, SEEK_SET); /*设置文件偏移量为32*/
    if (-1 == offset) {
        printf("Set offset %d failure\n", offset);
        return -1;
    }

    size = write(fd, buf2, len); /*将buf2中的数据写入到文件*/
    if (-1 == size) {
        return -1;
    }

    close(fd);
    return 0;
}
