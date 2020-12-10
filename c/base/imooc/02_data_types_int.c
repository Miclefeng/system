//
// Created by miclefengzss on 2020/12/7.
//

#include <stdio.h>
#include <limits.h>

void HelloWorld() {
  printf("Hello World!\n");
}

int main() {
  HelloWorld();

  // d = decimal
  // x = hex
  // o = oct
  // %hd: short decimal
  // %d: decimal
  // %ld: long decimal
  // %lld: long long decimal
  // %hu: unsigned short decimal
  // \n: new line
  // size_t
  short short_int = 123;
  printf("short_int = %hd\n", short_int);
  printf("LONG MAX = %ld\n", LONG_MAX);
  printf("sizeof(long int) = %lu\n", sizeof(long int));
  return 0;
}