//
// Created by miclefengzss on 2021/2/25.
//

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <io_utils.h>

void ReadFile() {
  // fgets() fputs() gets() puts() 都是针对文本文件，遇到 \n 会换行
  FILE *file = fopen("CMakeLists.txt", "r");
  if (file) {
    char buf[BUFSIZ];
    while (fgets(buf, BUFSIZ, file)) {
      printf("%s", buf);
    }
    fclose(file);
  } else {
    PRINT_INT(errno);
    puts(strerror(errno));
    perror("fopen");
  }
}

void Echo() {
  char buffer[1024];
  while (1) {
    if (!fgets(buffer, 1024, stdin)) {
      break;
    }
    printf("%s", buffer);
  }
}

int main() {
//  Echo();
  ReadFile();
  return 0;
}
