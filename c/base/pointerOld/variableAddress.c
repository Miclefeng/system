#include <stdio.h>

int main()
{
    char a; short b; int c; double d;

    printf("&a = %p\t", &a); printf("%#x\n", &a);
    printf("&b = %p\t", &b); printf("%#x\n", &b);
    printf("&c = %p\t", &c); printf("%#x\n", &c);
    printf("&d = %p\t", &d); printf("%#x\n", &d);
    return 0;
}

