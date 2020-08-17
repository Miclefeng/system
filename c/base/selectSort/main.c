#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initRand(int *arr, int n);
void display(int *arr, int n);
void selectSort(int *arr, int n);
int getSmallestIdx(int start, int *arr, int n);
void mySwap(int *pa, int *pb);

int main()
{
    int arr[10];

    initRand(arr, 10);
    display(arr, 10);
    selectSort(arr, 10);
    display(arr, 10);

    return 0;
}

void initRand(int *arr, int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d\t", *arr++);
    }
    putchar(10);
}

int getSmallestIdx(int start, int *arr, int n)
{
    int smallestIdx = start;
    for (int i = start + 1; i < n; i++) {
        if (arr[smallestIdx] > arr[i]) {
            smallestIdx = i;
        }
    }
    return smallestIdx;
}

void mySwap(int *pa, int *pb)
{
    *pa ^= *pb;
    *pb ^= *pa;
    *pa ^= *pb;
}

void selectSort(int *arr, int n)
{
    int idx;
    for (int i = 0; i < n - 1; i++) {
        idx = getSmallestIdx(i, arr, n);
        if (idx != i) {
            mySwap(&arr[i], &arr[idx]);
        }
    }
}
