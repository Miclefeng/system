#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
内存对齐 : 本质是牺牲空间，换取时间
1、 一个成语变量需要多个机器周期去读的现象，称为内存不对齐

对齐规则 :
#pragma pack(n) linux最大支持4字节对齐
1、取 pack(n)的值（n=1,2,4,8,12...）,取结构体中类型最大的值m。
两者取小即为外对齐大小 Y = (m<n?m:n)。
2、将每一个结构体的成员大小与Y比较取小者X，作为内对齐大小
3、所谓按X对齐，即为地址(设起始地址为0)能被X整除的地方开始存数据。
4、外部对齐原则是依据Y的值(Y的最小整数倍)，进行补空操作
用多个机器周期读取一个变量，造成的原因就是内存不对齐
#endif

struct Test
{
    char a;
    int b;
    short c;
}ts = {'a', 22, 66};

//struct stu
//{
//    char  a;  // 1
//    short b;  // 2
//    int   c;  // 4
//};

// 内存对齐
#pragma pack(4)
struct kk1
{
    char a;  // 1 <= 4, 对齐值为1
    short b; // 2 <= 4, 对齐值为2
    int c;   // 4 >= 4, 对齐值为4
    long d;  // 8 >= 4, 对齐值为4
}yy1;

// 内存对齐, 默认补齐
struct kk2
{
    char a;
    short b;
    int c;
    long d;
}__attribute__((aligned(1))) yy2;

// 内存对齐
struct kk3
{
    char a;
    short b;
    int c;
    long d;
}__attribute__((packed)) yy3;

typedef struct _stu
{
    char *name;
    int score;
} Stu;

#define offsetof(TYPE, MEMBER) ((int) &(((TYPE*)0)->MEMBER))
#define container_of(PTR, TYPE, MEMBER) (TYPE *)((char *)PTR - offsetof(TYPE, MEMBER))

int main()
{
    // 申请空间从外到内，释放空间从内到外
    Stu *ps = (Stu*)malloc(sizeof (Stu));
    ps->name = (char*)malloc(100);
    strcpy(ps->name, "miclefengzss");
    ps->score = 200;
    printf("name = %s\tscore = %d\n", ps->name, ps->score);

    free(ps->name);
    free(ps);

    printf("-----------------\n");
    printf("pragma pack(1)              = %d\n", sizeof (struct kk1));
    printf("pragma pack(1)              = %d\n", sizeof (yy1));
    printf("__attribute__((aligned(1))) = %d\n", sizeof (struct kk2));
    printf("__attribute__((aligned(1))) = %d\n", sizeof (yy2));
    printf("__attribute__((packed))     = %d\n", sizeof (struct kk3));
    printf("__attribute__((packed))     = %d\n", sizeof (yy3));

    int offset = 0;
    offset = (int)&(ts.c) - (int)&ts;
    printf("&ts.c - &ts = %d\n", offset);
    offset = offsetof(struct Test, c); // ((int) &(((struct Test*)0)->c))
    // (struct Test*)0 将0地址强制转换为 struct Test*类型的指针，然后使用这个 "0" 指针就能以 struct Test 的结构去访问
    // 0地址往后的 sizeof(struct Test) 大小的空间，此时 "0" 是结构体变量的首地址，借助 "0" 地址来进行模拟计算，不进行解引用就不会报错
    // 得到成员的地址后，强制转换为 int，成员地址在减去 "0" 的地址，就得到成员的偏移量
    printf("offsetof    = %d\n", offset);

    printf("struct Test*              = %p\n", &ts);
    printf("container_of struct Test* = %p\n", container_of(&ts.c, struct Test, c));
    // (struct Test*)((char *)&ts.c - ((int) &(((struct Test*)0)->c))
    // container_of 根据成员地址，获取结构体的地址
    // char *，指针运算 "成员指针 - 成员偏移量" 如果是 int * , "成员指针 - 成员偏移量*4(类型所占字节数)"
    // char *，进行指针运算 = 成员指针 - 成员偏移量*1
    return 0;
}
