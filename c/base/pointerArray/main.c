#include <stdio.h>
#include <string.h>

int main()
{
    char *cArr[] = {"china", "ameria", "canda", "japan"};

    int n = sizeof (cArr) / sizeof (*cArr);
    for (int i = 0;i < n; i++) {
        printf("%p  %s\n", cArr[i], *(cArr+i));
    }

    char *pt;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(cArr[i], cArr[j]) > 0) {
                pt = cArr[i];
                cArr[i] = cArr[j];
                cArr[j] = pt;
                //                *cArr[i] ^= *cArr[j];
                //                *cArr[j] ^= *cArr[i];
                //                *cArr[i] ^= *cArr[j];
            }
        }
    }
    puts("+++++++++++++++++++++");
    for (int i = 0;i < n; i++) {
        printf("%p  %s\n", cArr+i, *(cArr+i));
    }

    // auto 类型的局部变量存储在 stack 上，先声明的地址位高，stack 由高地址向低地址
    int a, b, c, d;
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);
    printf("%p\n", &d);
    return 0;
}
