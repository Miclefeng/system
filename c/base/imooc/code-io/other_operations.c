//
// Created by miclefengzss on 2021/3/3.
//

#include <io_utils.h>
#include <locale.h>
#include <sys/stat.h>

long GetFileSize(char const *filename) {
  struct stat st;
  stat(filename, &st);
  return st.st_size;
}

int IsDirectory(char const *filename) {
  struct stat st;
  stat(filename, &st);
  return st.st_mode & S_IFDIR;
}

int main() {
  setlocale(LC_ALL, "zh_CN.utf-8");
  int result = remove("data_copy/io_utils.h");
  PRINT_INT(result);
  result = remove("data_copy/io_utils.h");
  PRINT_INT(result);
  perror("remove()");
  PRINTLNF("===========================");
  result = rename("data/logos.bmp", "data/logo.bmp");
  PRINT_INT(result);

//  FILE *file = tmpfile();

  PRINT_LONG(GetFileSize("data/三国演义.txt"));
  PRINT_INT(IsDirectory("data/三国演义.txt"));
  PRINT_INT(IsDirectory("data"));

  return 0;
}