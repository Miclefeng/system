//
// Created by miclefengzss on 2020/12/21.
//

#include <stdlib.h>
#include <io_utils.h>

#define PLAYER_COUNT 10

typedef int (*Func)(int, double);

typedef int Boolean;
typedef int *IntPtr;
typedef int IntArray[];

int Add(int left, double right) {
  return (int) (left + right);
}

void InitPointer(int **ptr, int length, int default_value) {
  // 分配内存空间
  *ptr = malloc(sizeof(int) * length);
  for (int i = 0; i < length; ++i) {
    // 对每个空间进行赋值
    (*ptr)[i] = default_value;
  }
}

int main() {
  int a;
  IntPtr p;
  IntArray players = {0, 1, 2, 3, 4};
  PRINT_HEX(&main);
  PRINT_HEX(&InitPointer);

  PRINTLNF("=======================================");
  void (*func)(int **ptr, int length, int default_value) = &InitPointer;
  PRINTLNF("func()");
  func(&p, PLAYER_COUNT, 0);
  PRINT_INT_ARRAY(p, PLAYER_COUNT);
  PRINTLNF("InitPointer()");
  InitPointer(&p, PLAYER_COUNT, 0);
  PRINT_INT_ARRAY(p, PLAYER_COUNT);
  PRINTLNF("=======================================");
  PRINTLNF("(*func)()");
  (*func)(&p, PLAYER_COUNT, 0);
  PRINT_INT_ARRAY(p, PLAYER_COUNT);
  PRINTLNF("(*InitPointer)()");
  (*InitPointer)(&p, PLAYER_COUNT, 0);
  PRINT_INT_ARRAY(p, PLAYER_COUNT);
  free(p);
  Func func_1 = &Add;
  int s = func_1(1, 2.0);
  PRINT_INT(s);
  return 0;
}