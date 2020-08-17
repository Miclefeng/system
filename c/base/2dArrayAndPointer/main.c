#include <stdio.h>

int main() {
    int arr[3][4] = {1,2,3,4,10,20,30,40,100,200,300,400};
    for(int i=2; i>=0; i--) {
        for(int j=3; j>=0; j--)
        {
            printf("arr[%d][%d] = %#x\n", i, j,&arr[i][j]);
        }
        printf("----------------------\n");
    }
    printf("arr     = %#p arr+1     = %#x arr+2     = %#x \n", arr,arr+1,arr+2);
    printf("arr[0]  = %#p arr[0]+1  = %#x arr[0]+2  = %#x \n", arr[0],arr[0]+1,arr[0]+2);

    // 引用
    printf("&arr[0] = %#p &arr[0]+1 = %#x &arr[0]+2 = %#x \n", &arr[0],&arr[0]+1,&arr[0]+2);
    // 解引用
    printf("*arr    = %#p *arr+1    = %#x *arr+2    = %#x \n", *arr,*arr+1,*arr+2);

    // arr    -> *arr    -> arr[0]  解引用
    // arr[0] -> &arr[0] -> arr     引用

    printf("%d\n",arr[1][1]);

    // arr[1] = &arr[1][0](步长=4)的地址,然后 +1
    printf("arr[1]     = %p\n&arr[1]    = %p\n&arr[1][0] = %p\n", arr[1], &arr[1], &arr[1][0]);
    printf("%d\n",*(arr[1]+1));

    // arr = &arr[0]的地址, +1得到 &arr[1](步长=16), 在解引用得到 arr[1] = &arr[1][0](步长=4) 的地址,然后 +1 = arr[1][1]
    printf("%d\n",*(*(arr+1)+1));

    //arr[i] 第i行，首元素的地址 一级指针
    //arr+i 第 i 行的地址
    return 0;
}
