#include <stdio.h>

int main()
{
    int a[10] = {0xff,0x00,2,3,4,5,6,7,8,9};
    FILE *fp = fopen("test.txt", "wb+");
    if (NULL == fp)
        return -1;

    fwrite(a, sizeof (int[10]), 1, fp);
    rewind(fp);

    int n = 0;
    int data;

    while((n = fread(&data, sizeof (int), 1, fp)) > 0)
        printf("n = %d, data = %x\n", n, data);

    fclose(fp);

    return 0;
}
