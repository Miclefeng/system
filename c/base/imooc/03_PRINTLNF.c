//
// Created by miclefengzss on 2020/12/11.
//

#include <stdio.h>
#include <stdarg.h>

#define PRINTLNF(format, ...) printf("("__FILE__":%d) %s: "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)

// #value 获取原样输入的参数
#define PRINT_INT(value) PRINTLNF(#value" : %d", value)

// "Hello ""world" ==> "Hello world"
// __FILE__  获取文件所在位置
// __LINE__  获取文件行号  line 和 function 是编译阶段获取的
// __FUNCTION__ 获取方法名
// (../05.printlnf.c:20) main :

void PrintLnf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  printf("\n");
  va_end(args);
}

int main() {
  int x = 3;
  int y = 6;
  int z = 9;
  PrintLnf("x = %d, y = %d, z = %d", x, y, z);

  PRINTLNF("x = %d", x);

  PRINT_INT(4 + 9 * 6);
}