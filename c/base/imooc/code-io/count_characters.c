//
// Created by miclefengzss on 2021/3/3.
//

#include <io_utils.h>
#include <locale.h>
#include <wchar.h>

#define ERROR_ILLEGAL_FILENAME -1
#define ERROR_CANNOT_OPEN_FILE -2
#define ERROR_READ_FILE -3
#define ERROR_UNSUPPORTED_CHARSET -99

#define CHARSET_UTF8 0
#define CHARSET_GBK 1

int CountCharacterInFile(char const *file_name, int charset) {
  if (!file_name) {
    return ERROR_ILLEGAL_FILENAME;
  }

  FILE *file;

  switch (charset) {
    case CHARSET_GBK:
#ifdef __WIN32
      setlocale(LC_ALL, "chs");
#else
      setlocale(LC_ALL, "zh_CN.gbk");
#endif
      file = fopen(file_name, "r");
      break;
    case CHARSET_UTF8:setlocale(LC_ALL, "zh_CN.utf-8");
#ifdef __WIN32
      file = fopen(file_name, "r, ccs=utf-8");
#else
      file = fopen(file_name, "r");
#endif
      break;
    default:return ERROR_UNSUPPORTED_CHARSET;
  }

  if (!file) {
    return ERROR_CANNOT_OPEN_FILE;
  }

#define BUFFER_SIZE 512

  wchar_t wcs[BUFFER_SIZE];
  int count = 0;
  while (fgetws(wcs, BUFFER_SIZE, file)) {
    count += wcslen(wcs);
  }

  if (ferror(file)) {
    perror("CountCharactersInFile error");
    fclose(file);
    return ERROR_READ_FILE;
  }

  fclose(file);
  return count;
}

int main() {
  PRINT_INT(CountCharacterInFile("data/sanguo_gbk.txt", CHARSET_GBK));
  PRINT_INT(CountCharacterInFile("data/sanguo_utf8.txt", CHARSET_UTF8));
  return 0;
}