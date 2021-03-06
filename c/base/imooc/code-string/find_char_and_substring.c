//
// Created by miclefengzss on 2021/1/6.
//

#include <io_utils.h>
#include <string.h>

int main() {
  char *string = "Hello World!";
  char *result = strchr(string, 'l');
  char *result_reverse = strrchr(string, 'l');
  puts(result);
  puts(result_reverse);

  char *substring_position = strstr(string, "Wor");
  puts(substring_position);
  PRINT_INT(substring_position - string);

  char *string2 = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";
  char *break_set = ",;";

  int count = 0;
  char *p = string2;

  do {
    // 以 break_set 为分割符，分割字符串，并将分割后的位置返回
    p = strpbrk(p, break_set);
    if (p) {
      puts(p);
      p++;
      count++;
    }
  } while (p);

  PRINTLNF("Found %d characters.", count);
  return 0;
}
