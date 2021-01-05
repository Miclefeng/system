//
// Created by miclefengzss on 2021/1/5.
//

#include <io_utils.h>

/**
 * 判断字节序是否是大端序
 * @return
 */
int IsBigEndian() {
  union {
    char c_[2];
    short s_;
  } value = {.s_ = 0x100};

  return (int) value.c_ == 1;
}

int IsBigEndian2() {
  short s = 0x100;
  char *p = (char *) &s;
  PRINT_HEX(*(p + 1)); // *(p+1): 0x1 == p[1]
  // p[0] == *p
  return p[0] == 1;
}

int ToggleEndian(int original) {
  union {
    char c_[4];
    int i_;
  } value = {.i_ = original};

  char temp = value.c_[0];
  value.c_[0] = value.c_[3];
  value.c_[3] = temp;
  temp = value.c_[1];
  value.c_[1] = value.c_[2];
  value.c_[2] = temp;
  return value.i_;
}

/**
 * 转换 int 类型的字节序
 * @param original
 * @return
 */
int ToggleEndian2(int original) {
  char *p = (char *) &original;
  char temp = p[0];
  p[0] = p[3];
  p[3] = temp;
  temp = p[1];
  p[1] = p[2];
  p[2] = temp;
  return original;
}

int main() {
  PRINT_INT(IsBigEndian());
  PRINT_INT(IsBigEndian2());

  int original = 0x12345678;
  PRINT_HEX(ToggleEndian(original));
  PRINT_HEX(ToggleEndian2(original));
}