#include <stdio.h>

int main() {
    int data = 0x11223344;
    printf("%d\n", data);
    printf("%p\n", &data);
    printf("%p\n", (char *) &data);
    printf("%p\n", (short *) &data);
    printf("%p\n", (int *) &data);

    printf("\n");

    printf("%x\n",*(char *)&data);
    printf("%x\n",*(short *)&data);
    printf("%x\n",*(int *)&data);

    char c = 1;
    short s = 2;
    int i = 3;
    float f = 4.0;
    double d = 5.0;
}
