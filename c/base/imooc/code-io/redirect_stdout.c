//
// Created by miclefengzss on 2021/3/3.
//

#include <io_utils.h>
#include <locale.h>

#if defined(__APPLE__) || defined(__linux__)
#include <unistd.h>
#elif defined(__WIN32)
#include <io.h>
#endif

void RedirectStdout(char const *file_name) {
  static int saved_stdout_no = -1;
  if (file_name) {
    if (saved_stdout_no == -1) {
      /**
       * dup(oldfd) 产生 newfd 指向 oldfd 的指向文件
       * dup用来复制参数 oldfd 所指的文件描述符。
       * 当复制成功是，返回最小的尚未被使用过的文件描述符，若有错误则返回-1.
       */
      // 保存 stdout 的描述符
      saved_stdout_no = dup(fileno(stdout));
    }
    fflush(stdout);
    /**
     * 把一个新的文件名 file_name 与给定的打开的流 stream 关联，同时关闭流中的旧文件。
     */
    // stdout 重定向到 file_name
    freopen(file_name, "a", stdout);
  } else {
    if (saved_stdout_no != -1) {
      fflush(stdout);
      /**
       * dup2(oldfd, newfd) 将 newfd 指向 oldfd 的文件
       * dup2 与 dup 区别是 dup2 可以用参数 newfd 指定新文件描述符的数值。
       * 若参数 newfd 已经被程序使用，则系统就会将 newfd 所指的文件关闭，
       * 若 newfd 等于 oldfd，则返回 newfd ,而不关闭 newfd 所指的文件。
       *
       * fileno 获取文件描述符
       */
       // stdout 描述符重新指向之前保存的 stdout
      dup2(saved_stdout_no, fileno(stdout));
      /**
       * 关闭文件描述符
       */
      close(saved_stdout_no);
      saved_stdout_no = -1;
    }
  }
}

int main() {
  char *file_name = "data/output.log";
  puts("1");
  RedirectStdout(file_name);
  puts("2");
  RedirectStdout(NULL);
  puts("3");
  RedirectStdout(file_name);
  puts("4");
  RedirectStdout(NULL);
}