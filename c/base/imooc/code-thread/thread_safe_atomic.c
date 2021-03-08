//
// Created by miclefengzss on 2021/3/7.
//

#include <io_utils.h>
#include <tinycthread.h>

/**
 * 产生线程安全问题的原因
 * 1、对共享资源（全局变量、静态变量以及作用域比较大的每个线程都能访问到的资源）进行非原子访问
 * 2、不同线程之间代码的可见性
 * 3、线程内部代码编译时的重排序问题
 */
int count = 0;

int Counter(void *arg) {
  PRINTLNF("Counter.");
  for (int i = 0; i < 100000; ++i) {
    count++; // == int temp = count; count = temp + 1; temp 返回;
  }
  return count;
}

int main() {
  thrd_t thrd1, thrd2;

  thrd_create(&thrd1, Counter, NULL);
  thrd_create(&thrd2, Counter, NULL);

  thrd_join(thrd1, NULL);
  thrd_join(thrd2, NULL);

  PRINT_INT(count);
}