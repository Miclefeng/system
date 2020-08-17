#include <stdio.h>
#include <stdbool.h>

// 数组名是指针常量，方可唯一表示一个数组，数组名是唯一标识符，是基址
// 一维数组名可以赋值给一级指针
int main()
{
    int arr[10] = {2, 3, 6, 8, 9, 10, 12, 14, 16, 18};
    int *pa = arr; // pa 代表首元素的地址

    for (int i =0; i < 10; i++) {
        printf("%d\t", *(arr+i));
    }
    putchar(10);

    for (int i =0; i < 10; i++) {
        printf("%d\t", arr[i]);
    }
    putchar(10);
    for (int i =0; i < 10; i++) {
        printf("%d\t", pa[i]);
    }
    putchar(10);

    for (int i =0; i < 10; i++) {
        printf("%d\t", *pa++);
    }
    putchar(10);
    pa = arr;

    bool digit_seen[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    // 对10取余，取出数最后一位，放入数组，然后 /10 在取余
    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            break;
        }
        digit_seen[digit] = true;
        n /= 10;
    }

    if (n > 0) {
        printf("Repeated digit\n");
    } else {
        printf("No repeated digit\n");
    }

    int a[] = {4, 9, 1, 8, [0] = 5, 7}; // a = {5 7 1 8}
    for (int i = 0; i < sizeof (a) / sizeof (a[0]); i++) {
        printf("%d\t", a[i]);
    }
    puts("");
    return 0;
}
