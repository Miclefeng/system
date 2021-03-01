#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void bubblingSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
     }
}

int main(void)
{
    int i;
    int arr[11] = {6, 1, 7, 0, 2, 8, 5, 4, 3, 9, 10};
    bubblingSort(arr, 11);
    for (i = 0; i < 11; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

