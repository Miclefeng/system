#include <stdio.h>
#include <stdarg.h>

double average(int n_values, ...);

int main()
{
    int n_values = 3;
    int a = 10;
    int b = 11;
    int c = 12;

    printf("%.2f\n", average(n_values, a, b, c));
    return 0;
}

double average(int n_values, ...)
{
    va_list var_arg;
    int count;
    double sum = 0;

    // 准备可变参数
    va_start(var_arg, n_values);

    for (count = 0; count < n_values; count++) {
        // 取可变参数列表的值
        sum += va_arg(var_arg, int);
    }

    // 完成处理可变参数
    va_end(var_arg);

    printf("sum = %.2f, num = %d\n", sum, n_values);
    return sum / n_values;
}
