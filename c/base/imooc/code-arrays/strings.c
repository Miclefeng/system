//
// Created by miclefengzss on 2020/12/14.
//

#include <stdio.h>
#include <stddef.h>
#include "io_utils.h"

int main() {
  char string[] = "Hello World";

  for (int i = 0; i < 11; ++i) {
    PRINT_CHAR(string[i]);
  }

  // short %hd
  // NULL \0
  PRINTLNF("%s", string);

  char string_zh[] = "你好，中国";

  wchar_t ws[] = L"你好，中国";
  PRINTLNF("%s", string_zh);
  PRINTLNF("%x", ws);
  return 0;
}