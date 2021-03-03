//
// Created by miclefengzss on 2021/3/3.
//

#include <io_utils.h>
#include <locale.h>

int main() {
  FILE *file = fopen("CMakeLists.txt", "rb");
  long position = ftell(file);
  PRINT_LONG(position);
  char buf[128];
  fread(buf, 1, 128, file);
  PRINT_LONG(ftell(file));

  fseek(file, 10, SEEK_SET);
  PRINT_LONG(ftell(file));
  fseek(file, 10, SEEK_CUR);
  PRINT_LONG(ftell(file));
  fseek(file, -10, SEEK_END);
  PRINT_LONG(ftell(file));

  fclose(file);

  ftell(stdout); // error
  perror("ftell(stdout)");
  return 0;
}