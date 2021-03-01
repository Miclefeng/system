//
// Created by miclefengzss on 2021/3/1.
//

#include <stdio.h>

struct student {
  char name[32];
  char score;
};

int main() {
  struct student a[10], st;
  int i, j, n, maxIdx;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s %c", a[i].name, &a[i].score);
  }

  for (i = 0; i < n; i++) {
    maxIdx = i;
    for (j = i + 1; j < n; j++) {
      if (a[maxIdx].score < a[j].score) {
        maxIdx = j;
      }
    }
    st = a[i];
    a[i] = a[maxIdx];
    a[maxIdx] = st;
  }

  for (i = 0; i < n; i++) {
    printf("%s %c\n", a[i].name, a[i].score);
  }

  return 0;
}