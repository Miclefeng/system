#include <stdio.h>

// typedef 常用于对结构体起别名的关键字
#if 0
typedef 只能对已有类型起别名，构成c语言语句参与编译
1、 用现有类型生成变量
2、 在变量定义之前加 typedef
3、 将定义的变量换成你要的别名

#define 构成宏，在预处理阶段处理完毕
#endif
typedef struct stu
{
    int age;
    char name;
    float score;
} Stu;

struct _stu
{
    int age;
    int gender;
    char name[];
};

int main()
{
    Stu s1;
    struct _stu man;
    printf("Hello World!\n");
    /*
     ** 非法表达式
     */
    int i = 10;
    i = i-- - --i * (i = -3) * i++ + ++i;
    printf("i = %d\n", i);
    return 0;
}
