#include <stdio.h>

int even_parity(int value, int n_bits);
void swap(int *x, int *y);

int main()
{
    int value = 0;
    int n_bits = 1;

    printf("%d\n", even_parity(value, n_bits));

    int x = 10, y = 20;
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}

int even_parity(int value, int n_bits)
{
    int parity = 0;

    /*
     ** 计数值中值为1的位的个数
     */
    while (n_bits > 0) {
        parity += value & 1;
        value >>= 1;
        n_bits -= 1;
    }

    return (parity % 2) == 0;
}

void swap(int *x, int *y)
{
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}
