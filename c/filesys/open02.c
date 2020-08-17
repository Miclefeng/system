#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = -1;
    // char filename[] = "/dev/vda1";
    char filename[] = "test.txt";

    fd = open(filename, O_RDWR | O_CREAT | O_EXCL, S_IRWXU);
    if (-1 == fd) {
        printf("File %s existed!, reopen it\n", filename);
    } else {
        printf("Open file %s success, fd : %d\n", filename, fd);
    }

    return 0;
}
