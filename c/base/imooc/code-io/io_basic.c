//
// Created by miclefengzss on 2021/1/28.
//

#include <stdio.h>
#include <io_utils.h>
#include <errno.h>
#include <string.h>

char std_buffer[BUFSIZ];

int main() {

  setbuf(stdout, std_buffer);

  FILE *file = fopen("CMakeLists.txt", "r");
  char buf[8192];
  /**
   * 设置缓冲区大小(缓冲区的生命周期要大约文件流的生命周期)
   * 1、在静态数据区开辟，放到全局作用域
   * 2、使用malloc在堆上进行内存开辟，释放文件流之后再释放缓冲区，或者为文件流重新开辟一块内存缓冲
   * _IOFBF  全量缓冲，适合缓冲二进制文件
   * _IOLBF  按行缓冲，适合缓冲文本文件
   * _IONBF  禁用缓冲
   */
  setvbuf(file, buf, _IOLBF, 8192);

  if (file) {
    puts("open file successfully.");
    int err = ferror(file);
    PRINT_INT(err);
    int eof = feof(file);
    PRINT_INT(eof);
    fflush(stdout);
    fclose(file);
  } else {
    perror("fopen");
  }

  for (int i = 0; i < 10; ++i) {
    PRINT_INT(i);
    puts(strerror(i));
  }

  // 清空缓冲区的数据
  fflush(stdout);

  stdout;
  stderr;
  stdin;
  return 0;
}