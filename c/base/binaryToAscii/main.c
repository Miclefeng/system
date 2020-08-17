#include <stdio.h>

void binary_to_ascii(unsigned int value);
// n 的阶乘
long factorial(int n);
// 斐波那契数列
long fibnacci(int n);

int main()
{
    unsigned int num = 19940202;
    binary_to_ascii(num);
    puts(" ");

    int n = 7;
    printf("factorial = %ld\n", factorial(n));
    printf("fibnacci = %ld\n", fibnacci(n));
    printf("=======================\n");
    size_t i = 0;
    int cnt = -1;
    for (i = cnt - 2; i < cnt; i--) {
        printf("This is %d, i = %d;\n", i < cnt, i);
        break;
    }

    printf("==========================\n");

    int x = 1;
    printf("%x\n", x>>31);

    return 0;
}

void binary_to_ascii(unsigned int value)
{
    unsigned int quotient;

    quotient = value / 10;
    if ( quotient != 0) {
        binary_to_ascii(quotient);
    }
    printf("%c - ", value % 10 + '0');
    printf("%d | ", value % 10 + '0');
}

long factorial(int n)
{
    //    if (n <= 0) {
    //        return 1;
    //    } else {
    //        return n * factorial(n - 1);
    //    }
    int result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

long fibnacci(int n)
{
    //    if (n <= 2) {
    //        return 1;
    //    }
    //    return fibnacci(n - 1) + fibnacci(n - 2);
    long current;
    long previous;
    long last_previous;

    previous = current = 1;

    while (n > 2) {
        last_previous = previous;
        previous = current;
        current = last_previous + previous;
        n--;
    }

    return current;
}
