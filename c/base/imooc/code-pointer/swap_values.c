//
// Created by miclefengzss on 2020/12/22.
//

#include <stdlib.h>
#include <io_utils.h>
#include <string.h>

void SwapInt(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Swap(void *a, void *b, size_t size) {
  void *temp = malloc(size);
  if (temp) {
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
  } else {
    // error deal
  }
}

// msvc c++ decltype(a) 获取变量类型
// 添加 do while 防止 {} 和外部 {} 冲突
#define SWAP(a, b, type) do { type temp = a; a = b; b = temp; } while (0)
// gcc c typeof(a) 获取变量类型
#define SWAP_EXT(a, b) do { typeof(a) temp = a; a = b; b = temp; } while(0)

int main() {
  int a = 3;
  int b = 4;
  SwapInt(&a, &b);
  PRINT_INT(a);
  PRINT_INT(b);
  PRINTLNF("======================");
  double x = 5.0;
  double y = 8.0;
  // x,y 是 double类型 8字节，SwapInt 中参数值类型为 int 4字节，x,y double类型的低4字节都是0，进行交换没有任何作用
  SwapInt(&x, &y);
  PRINT_DOUBLE(x);
  PRINT_DOUBLE(y);
  PRINTLNF("Really Swap:");
  Swap(&x, &y, sizeof(double));
  SWAP(x, y, double);
  SWAP_EXT(x, y);
  PRINT_DOUBLE(x);
  PRINT_DOUBLE(y);

}