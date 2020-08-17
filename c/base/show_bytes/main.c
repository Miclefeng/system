#include <stdio.h>


typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);

void show_int(int x);

void show_float(float x);

void show_double(double x);

void show_pointer(void *x);

int main()
{
    int a = 4;
    float b = 4.0;
    void *c = &b;
    double d = 6.0;

    show_int(a); // 0x04 00 00 00  小端序
    show_float(b); // 0x00 00 80 40
    show_double(d); // 0x00 00 00 00 00 00 18 40 ，64位机器 double 占8位
    show_pointer(c); // 0x04 3B 5E ED FE 7F 00 00 ，64位机器 *T 占8位

    return 0;
}

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2X", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof (int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof (float));
}

void show_double(double x)
{
    show_bytes((byte_pointer) &x, sizeof (double));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof (void *));
}
