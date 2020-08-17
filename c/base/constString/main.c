#include <stdio.h>

// c中字符串常量 == 指向 data 段的该字符串的首地址
// char* 可以表示整个字符串，起始地址 步长 \0(终止标记)
int main()
{
    printf("sizeof(\"miclefeng\") = %d\n", sizeof ("miclefeng"));
    char *p = "miclefeng";

    printf("p = %p p + 1 = %p p[0] = %c 0[p] = %c\n", p, p+1, p[0], 0[p]);
    printf("  = %p   + 1 = %p, [0] = %c, 0[] = %c\n", "miclefeng", "miclefeng"+1, "miclefeng"[0], 0["miclefeng"]);

    // arr[]是栈上的空间    "china"是data中的一块常量空间
    // 等价  sizeof(字符数组) >= sizeof(字符串的大小)
    char arr[] = "china";

    printf("arr       = %s\n", arr);
    arr[2] = 'x';
    printf("arr       = %s\n", arr);
    printf("\"china\"   = %s\n", "china");

    return 0;
}
