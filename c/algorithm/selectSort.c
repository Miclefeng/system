#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

/**
 * @param
 * @param
 */
void selectSort(int arr[], int n)
{
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

int main(void)
{
    int i;
    int arr[10] = {9, 8, 6, 2, 1, 5, 4, 3, 7, 10};
    selectSort(arr, 10);
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

