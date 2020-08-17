#include <stdio.h>
#include "add.h"
#include "sub.h"

int main(void)
{
    int a = 10, b = 12;
    float x = 1.23456, y = 9.87654321;

    printf("Int a + b Is : %d\n", add_int(a, b));
    printf("Int a - b Is : %d\n", sub_int(a, b));
    printf("Float x + y Is : %f\n", add_float(x, y));
    printf("Float x - y Is : %f\n", sub_float(x, y));
    return 0;
}
