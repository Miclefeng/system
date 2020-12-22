//
// Created by miclefengzss on 2020/12/21.
//

#include <stdio.h>
#include <io_utils.h>

int SumIntArray(const int array[], int length) {
  int sum = 0;
  for (int i = 0; i < length; ++i) {
    sum += array[i];
  }
  return sum;
}

void SumIntArray2(const int array[], int length, int *sum) {
  for (int i = 0; i < length; ++i) {
    *sum += array[i];
  }
}

int main() {
  int array[] = {0, 1, 2, 3, 4, 5};
  int sum = SumIntArray(array, 6);

  int sum_2 = 0;
  SumIntArray2(array, 6, &sum_2);

  PRINT_INT(sum);
  PRINT_INT(sum_2);
  return 0;
}