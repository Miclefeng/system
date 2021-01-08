//
// Created by miclefengzss on 2021/1/5.
//

#include <io_utils.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  char const *const kInput = "1 200000000000000000000000000000 3 -4 5abcd bye";
  PRINTLNF("Parse: %s", kInput);

  char const *start = kInput;
  char *end;

  while (1) {
    // 清空错误
    errno = 0;

    // 从 start 开始读，读取到 end 并返回读取字符转换为long的结果
    const long kI = strtol(start, &end, 10);

    if (start == end) {
      break;
    }

    printf("'%.*s'\t===> %ld", (int) (end - start), start, kI);
    if (errno == ERANGE) {
      perror("");
    }

    puts("\n");
    start = end;
  }

  PRINTLNF("Left: %s", start);
}
