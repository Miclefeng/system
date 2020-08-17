#include <stdio.h>

int func (void)
{
    static int counter;
    return ++counter;
}

int main()
{
    int answer;

    answer = func() - func() * func();
    printf("%d\n", answer);
    return 0;
}

