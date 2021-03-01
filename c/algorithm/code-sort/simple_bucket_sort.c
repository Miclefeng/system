//
// Created by miclefengzss on 2021/3/1.
//

#include <stdio.h>

int main() {
  int a[11], i, j, t;

  /**
   * 简单桶排序
   * 将数据元素放到不同的数组索引上，相同的索引对应的值++，然后打印索引大于0的数据
   */
  for (i = 0; i < 11; i++) {
    a[i] = 0;
  }

  for (i = 0; i < 5; i++) {
    scanf("%d", &t);
    a[t]++;
  }

  for (i = 10; i >= 0; i--) {
    for (j = 1; j <= a[i]; j++) {
      printf("%d ", i);
    }
  }

  return 0;
}
