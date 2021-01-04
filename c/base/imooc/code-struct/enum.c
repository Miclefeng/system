//
// Created by miclefengzss on 2021/1/4.
//

#include <io_utils.h>

typedef enum FileFormat {
  PNG, JPEG, BMP, UNKNOWN
} FileFormat;

FileFormat GuessFormat(char *file_path) {
  FILE *file = fopen(file_path, "r");
  FileFormat file_format = UNKNOWN;

  if (file) {
    char buffer[8] = {0};
    size_t bytes_count = fread(buffer, 1, 8, file);
    if (bytes_count == 8) {
      if (*((short *) buffer) == 0x4D42) {
        file_format = BMP;
      } else if (*((long *) buffer) == 0x0A1A0A0D474E5089) {
        file_format = PNG;
      } else if (*((int *) buffer) == 0xE0FFD8FF) {
        file_format = JPEG;
      }
    }
    fclose(file);
  }
  return file_format;
}

int main() {
  PRINT_INT(GuessFormat("images/c.png"));
  PRINT_INT(GuessFormat("images/c.jpeg"));
  PRINT_INT(GuessFormat("images/c.bmp"));
  PRINT_INT(GuessFormat("images/c.webp"));
}