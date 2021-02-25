//
// Created by miclefengzss on 2021/2/24.
//
#include <stdio.h>
#include <io_utils.h>
#include <errno.h>
#include <string.h>

void ReadFile() {
  FILE *file = fopen("CMakeLists.txt", "r");

//  getchar() == getc(stdin);
  if (file) {
    int next_char = getc(file);
    while (next_char != EOF) {
      putchar(next_char);
      next_char = getc(file);
    }
    fclose(file);
  } else {
    PRINT_INT(errno);
    puts(strerror(errno));
    perror("fopen");
  }
}

int main() {
  ReadFile();
  return 0;
}