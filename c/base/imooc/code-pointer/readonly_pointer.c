//
// Created by miclefengzss on 2020/12/17.
//

#include <stdio.h>
#include <io_utils.h>

int main() {
  int a;
  int b;
  int *p = &a;
  PRINT_HEX(p);
  PRINT_HEX(&a);

  PRINT_INT(sizeof(int *));

  PRINT_INT(*p);
  PRINT_INT(a);

  int **pp = &p;
  // *pp => p;

  *p = 20;
  PRINT_INT(*p);
  PRINT_INT(a);

  // 从 const 往前读
  // 只读指针变量
  int *const cp = &a;
  *cp = 2; // OK
  // cp = &b; ERROR
  // 只读变量指针
  int const *cp2 = &a;
  // *cp2 = 2; ERROR
  cp2 = &b; // OK

  // 只读变量的只读指针变量
  int const *const ccp = &a;
  // ccp = &b; ERROR
  // *ccp = 2; ERROR
  return 0;
}