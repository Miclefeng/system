//
// Created by miclefengzss on 2021/1/6.
//

#include <io_utils.h>
#include <string.h>
#include <stdlib.h>

int main() {
  // memchr()
  // strchr()

  // memcmp()
  // strcmp()

  // 初始化内存
  // memset()
  char *mem = malloc(10);
  memset(mem, 0, 10);

  PRINT_INT_ARRAY(mem, 10);
  free(mem);

  // memcpy
  // strcpy

  // memmove 两个重叠的内存区域复制使用
  // memmove()

  char src[] = "HelloWorld";
  char *dest = malloc(11);
  memset(dest, 0, 11);
  // 不重叠的内存区域复制使用
  memcpy(dest, src, 11);
  puts(dest);
  memmove(dest + 3, dest + 1, 4);
  puts(dest);
  free(dest);
  return 0;
}
