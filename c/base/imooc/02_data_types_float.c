//
// Created by miclefengzss on 2020/12/7.
//

#include <stdio.h>

int main() {
  float a_float = 3.14f; // 6, 7~8 +-10^-37 ~ 10^37
  printf("size of float: %lu\n", sizeof(float));
  double a_double = 3.14; // 15~16
  printf("size of double: %lu\n", sizeof(double));

  float lat = 39.90815f;
  int lat06 = (int) (lat * 1e6);
  printf("%f\n", 39.908156f - lat);
  printf("%d\n", lat06);

  float money = 3.14f; // error, never use float or double to describe money
  return 0;
}