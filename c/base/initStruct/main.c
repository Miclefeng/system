#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 初始化是一种特殊的语法和赋值不等价
// 凡是 基本类型 既可以定义的时候初始化，也可以先定义后赋值
// 凡是 构造类型 要么在定义的时候初始化，不可以先定义在初始化赋值
// 相同结构体类型的变量间，可以赋值。
#if 0
访问 ：
栈上访问       堆上访问

指向成员运算符  点成员运算符
#endif

typedef struct stu
{
    char  name[30];
    int   age;
    char  gender;
    float score;
}Stu;

int main()
{
//    char name[30] = "china"; // 定义的时候初始化
//    name = "miclefeng";  错误，数组名为常量指针类型，不能赋值

//    struct stu s = {"miclefeng", 27, 'f', 100.0};
    struct stu s;
//    s.name = "miclefeng"; 错误，数组名为常量指针类型，不能赋值
    strcpy(s.name, "miclefeng");
    s.age = 27;
    s.gender = 'f';
    s.score = 100.0;
    printf("name   = %s\nage    = %d\ngender = %c\nscore  = %.2f\n", s.name, s.age, s.gender, s.score);

    struct stu *ps = &s;
    printf("name   = %s\n",   ps->name); // 指向成员运算符
    printf("age    = %d\n",   ps->age);
    printf("gender = %c\n",   ps->gender);
    printf("score  = %.2f\n", ps->score);

    printf("name   = %s\n",   (*ps).name); // 点成员运算符
    printf("age    = %d\n",   (*ps).age);
    printf("gender = %c\n",   (*ps).gender);
    printf("score  = %.2f\n", (*ps).score);

    Stu *pt = (Stu*)malloc(1*sizeof (Stu));
    strcpy(pt->name, "micle");
    pt->age    = 27;
    pt->gender = 'f';
    pt->score  = 100.0;

    printf("name   = %s\n",   pt->name); // 指向成员运算符
    printf("age    = %d\n",   pt->age);
    printf("gender = %c\n",   pt->gender);
    printf("score  = %.2f\n", pt->score);
    free(pt);
    pt = NULL;
    return 0;
}
