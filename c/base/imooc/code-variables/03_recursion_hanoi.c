//
// Created by miclefengzss on 2020/12/9.
//

#include <stdio.h>

void Move(int n, char src, char dest, char temp);

int main() {
  Move(3, 'A', 'C', 'B');
  return 0;
}

/**
 * 递归方式实现汉诺塔问题
 *
 * @param n
 * @param src
 * @param dest
 * @param temp
 */
void Move(int n, char src, char dest, char temp) {
  if (n == 0) {
    return;
  } else if (n == 1) {
    printf("%c ------> %c\n", src, dest);
  } else {
    Move(n - 1, src, temp, dest);
    Move(1, src, dest, temp);
    Move(n - 1, temp, dest, src);
  }
}