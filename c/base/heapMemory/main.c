#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// heap    内存，可以申请大空间，需要手动申请和释放，申请的空间从低地址位到高地址位
// malloc  以字节为单位进行申请
// memset  初始化内存申请 以字节为单位
// calloc  申请内存并初始化(单元数，每个单元的字节大小) == malloc + memset
// realloc 扩容/缩容原内存的大小(待扩容/缩容的指针，新的内存大小)
// free    释放内存
// malloc  和 free 要配对使用，malloc > free = 内存泄露 ， free > malloc = double free

// 内存申请步骤：  申请(malloc) -> 判空(!=NULL) -> 使用(*ptr = memory) -> 释放(free) -> 置空(*ptr = NULL)
// 申请空间的时候从外到内， 释放空间的时候从内到外
// 哪里申请哪里释放
// 数值可以返回    地址可以返回     栈上的空间不可以返回(随用随开，用完即消)    堆上的空间可以返回
// 内存以字节为单位进行线性编址的硬件基础，类型是对内存的格式化
// VLD 检测内存泄漏
int main()
{
    int *p = (int*)malloc(1 * sizeof (int));
    *p = 100;
    printf("*p = %d\n", *p);
    free(p);
    // 数组类型在堆和栈上
    int arr[10];

    int *pa = (int*)malloc(10 * sizeof (int));
    // 每个字节设置为 1，4个字节为 01010101
    memset(pa, 1, 10 * sizeof (int));
    for (int i = 0; i < 10; i++) {
        printf("%d\n", pa[i]);
    }
    free(pa);

    char *pr = (char*)malloc(1);
    pr = realloc(pr, 20);
    strcpy(pr, "1234567890abcdef");
    printf("pr = %s\n", pr);
    free(pr);

    return 0;
}
