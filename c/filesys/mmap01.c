#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>

#define FILELENGTH 80

int main(void)
{
    int fd = -1;
    /*将要写入文件的字符串*/
    char buf[] = "quick brown fox jumps over the lazy dog";

    char *ptr = NULL;

    fd = open("mmap.txt", O_RDWR | O_CREAT | O_TRUNC/*清空文件*/, S_IRWXU);
    if (-1 == fd) {
        return -1;
    }

    /*将文件的长度扩大为80，并向后偏移79*/
    lseek(fd, FILELENGTH - 1, SEEK_SET);
    write(fd, "a", 1);

    /*将文件mmap.txt数据段从开头到1M之间的数据映射到内存中，对文件的操作立刻显示在文件上*/
    ptr = (char *)mmap(NULL, FILELENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if ((char*)-1 == ptr) {
        printf("Mmap failure\n");
        close(fd);
        return -1;
    }

    memcpy(ptr + 16, buf, strlen(buf));
    munmap(ptr, FILELENGTH);

    close(fd);
    return 0;
}
