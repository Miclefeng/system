//
// Created by miclefengzss on 2021/3/3.
//

#include <io_utils.h>
#include <tinycthread.h>

int SayHello(char *name) {
  PRINTLNF("Run in new thread[%#x]: Hello %s", thrd_current(), name);
  return 1;
}

int main(void) {
  thrd_t thrd;
  /**
   * thrd_create 创建新的线程,(线程的类型地址，线程的函数指针，函数的参数)
   */
  int result = thrd_create(&thrd, SayHello, "Miclefeng");
  if (result == thrd_success) {
    PRINTLNF("Run in main thread[%#x], create new thread[%#x]", thrd_current(), thrd);
  } else {
    PRINTLNF("Run in main thread[%#x], failed create new thread", thrd_current());
  }
  /**
   * thrd_sleep 线程休眠时间 (timespec结构体， 需要保留的值)
   */
//  thrd_sleep(&(struct timespec) {.tv_sec=0, .tv_nsec=100000000}, NULL);
  int res;
  /**
   * 等待子线程完成，并将接收结果 并释放线程资源
   */
  thrd_join(thrd, &res);
  PRINTLNF("Run in main thread[%#x], result from thread[%#x]: %d", thrd_current(), thrd, res);

  /**
   * thrd_yield 让出CPU时间片
   */
   /**
    * 等待子线程完成，并释放线程资源（和thrd_join互斥）
    */
//    thrd_detach(thrd);
  return 0;
}