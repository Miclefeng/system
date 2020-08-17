#include <stdio.h>

// 数组的传递不可能通过拷贝的方式传递。在传递的时候，数组名仅充当地址使用。
// 数组三要素： 起始地址，步长，范围
// 数组名是一个指针，包含起始地址和步长
// 数组传递的时候要传数组名和范围
void disArray(int arr[], int n);

int main()
{
    int arr[] = {0, 2, 4, 6, 8, 10};
    printf("main sizeof(arr) = %d\n", sizeof (arr));
    disArray(arr, sizeof (arr) / sizeof (*arr)); // *arr == arr[0]
    return 0;
}

void disArray(int arr[], int n)
{
    printf("disArray sizeof(arr) = %d\n", sizeof(arr));

    for (int i = 0; i < n; i++) {
        printf("%d\t", *arr++); // *arr++ == *(arr++) == arr[i]
    }
    putchar(10);
}
