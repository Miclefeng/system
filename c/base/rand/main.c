#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(int i)
{
    if (i > 0) {
        func(i / 2);
    }
    printf("%d\t", i);
}

int main()
{
    unsigned int seed;
    int randArr[10];
    int count;
    int num;

    seed = (unsigned int) time(NULL);
    srand(seed);
    count = 0;

    while(count < 10) {
        num = rand() % 10;
        randArr[count++] = num;
        for (int i = 0; i < count - 1; i++) {
            if (num == randArr[i]) {
                count--;
                break;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", randArr[i]);
    }
    putchar(10);

    func(10);
    putchar(10);
    return 0;
}
