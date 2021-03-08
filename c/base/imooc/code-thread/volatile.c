//
// Created by miclefengzss on 2021/3/7.
//

#include <io_utils.h>
#include <tinycthread.h>

/**
 * 使用 volatile 修饰的变量再被访问的时候，无论读写都被视为一个可观察到的副作用，禁止编译器被
 * 所修饰的变量进行重排序
 * volatile 确保被修饰的变量读写操作不被编译器优化
 * volatile 不会保证访问的原子性
 */
volatile int flag = 0;

int a = 0;
int x = 0;

int T1(void *arg) {
  a = 2;
  flag = 1;
  a = a + 3;
  return 0;
}

int T2(void *arg) {
  while (!flag) {}
  x = a * a;
  return 0;
}

int main() {
  thrd_t thrd1, thrd2;

  thrd_create(&thrd2, T2, NULL);
  thrd_create(&thrd1, T1, NULL);

  thrd_join(thrd1, NULL);
  thrd_join(thrd2, NULL);

  PRINT_INT(x);
}