#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd = -1, i;
    ssize_t size = -1; /*存储数据到缓冲区*/
    char buf[10];
    char filename[] = "test.txt";

    printf("%d\n\n", i);
    fd = open(filename, O_RDONLY); /*只读方式打开，如果不存在报错*/

    if (-1 == fd) {
        printf("Open file %s failure,fd : %d\n", filename, fd);
    } else {
        printf("Open file %s success,fd : %d\n", filename, fd);
    }

    while (size) {
        size = read(fd, buf, 10);
        if (-1 == size) {
            close(fd);
            printf("read file error occurs!\n");
            return -1;
        } else {
            if (size > 0) {
                printf("\n%s\n", buf);
                printf("read %d bytes: ", size);
                printf("\"");
                for (i = 0; i < size; i++) {
                    // *buf 指向第一个字节 , *buf+i 请指针指向第i个字节
                    // printf("%c", *(buf + i)); /*将获取的字符打印出来*/
                    printf("%c", buf[i]);
                }
                printf("\"\n");
            } else {
                printf("reach the end of file");
            }
        }
    }

    return 0;
}
