#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swap(int *p1, int *p2) {
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

/**
 * @param
 * @param
 */
void selectSort(int arr[], int n) {
  /**
   * 选着排序，，每趟将最小/最大的数放到当前趟起始的位置，开始(i=0)，后续每趟起始位置为(i++)
   * 比较两个数(两个数的比较起始位置为i+1，因为前i个数已经是排好序的)然后交换索引，每趟比较完之后在进行值交换。
   */
  int i, j, minIndex;
  for (i = 0; i < n; i++) {
    minIndex = i;
    for (j = i + 1; j < n; j++) {
      if (arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }
    swap(&arr[i], &arr[minIndex]);
  }
}

int main(void) {
  int i;
  int arr[10] = {9, 8, 6, 2, 1, 5, 4, 3, 7, 10};
  selectSort(arr, 10);
  for (i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}

