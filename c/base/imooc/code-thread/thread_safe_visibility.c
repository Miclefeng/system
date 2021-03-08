//
// Created by miclefengzss on 2021/3/7.
//

#include <io_utils.h>
#include <tinycthread.h>

int flag = 0;

int a = 0;
int x = 0;

int T1(void *arg) {
  a = 2;
  flag = 1;
  return 0;
}

int T2(void *arg) {
  while (!flag) {}
  x = a * a;
  return 0;
}

int main() {
  thrd_t thrd1, thrd2;

  thrd_create(&thrd1, T1, NULL);
  thrd_create(&thrd2, T2, NULL);

  thrd_join(thrd1, NULL);
  thrd_join(thrd2, NULL);

  PRINT_INT(x);
}