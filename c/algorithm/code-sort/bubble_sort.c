//
// Created by miclefengzss on 2021/3/1.
//

#include <stdio.h>

struct student {
  char name[32];
  char score;
};

int main() {
  struct student a[100], st;

  int i, j, n;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %c", a[i].name, &a[i].score);
  }

  /**
   * 冒泡排序:每一趟只能将一个数归位，n个数需要n-1趟，每一趟需要进行两个元素的比较交换，已归位的数不需要
   * 交换，所有后续的每趟需要排除已归位的数(n-i-1)
   */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (a[j].score < a[j + 1].score) {
        st = a[j];
        a[j] = a[j + 1];
        a[j + 1] = st;
      }
    }
  }

  for (i = 0; i < n; i++) {
    printf("%s %c \n", a[i].name, a[i].score);
  }
  return 0;
}