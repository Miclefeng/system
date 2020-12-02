//
//  main.cpp
//  pointer
//
//  Created by miclefengzss on 2020/11/29.
//

#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
    // insert code here...
    int numbers[] = {1, 2};
    cout << "numbers[0] = " << numbers[0] << endl;
    cout << "numbers[1] = " << *(numbers + 1) << endl;

    cout << endl;
    cout << "===================" << endl;

    // new 进行内存分配，有可能产生内存溢出异常，需要进行捕获
    int *pi = new int;
    *pi = 1234;
    cout << "*pi = " << *pi << endl;

    auto *pd = new double;
    *pd = 1.23456;
    cout << "pd address before delete: " << pd << endl;
    cout << "*pd = " << *pd << endl;

    // delete 进行内存释放
    /**
     * 1. delete 只能释放 new 分配的空间，不能释放 malloc 及相关函数分配的内存空间
     * 2. 普通变量在栈上进行内存分配，系统会自动回收内存空间；使用 new / malloc 等动态分配的内存空间(在堆上进行内存分配)，需要手动释放
     * 3. delete 之后，指针本身和指针指向空间的数据不会被清空，除非再次写入数据
     * 4. 如果有多个指针指向同一个内存空间，只要释放一个指针，其它的就都会释放
     * 5. 对于已经释放了的指针所指向的内存空间，不能再次释放
     */
    delete pi;
    delete pd;

    cout << "pd address after delete: " << pd << endl;
    cout << "*pd = " << *pd << endl;
    cout << "===================================" << endl;

    int *array;
    array = new int[10];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    delete[] array;

    array = new int[20];
    array[0] = 10;
    array[1] = 11;

    cout << "array[0] = " << array[0] << endl;
    cout << "array[1] = " << array[1] << endl;
    cout << "array[2] = " << *(array + 2) << endl;
    delete[] array;
    array = nullptr;
    cout << "===================================" << endl;


    /**
     * const 在谁前面就修饰谁 类型(typename) 或者 变量 (variable)
     * 常量指针: 指针所指向的空间存储的数据是常量，只读不允许修改
     */
    const int code = 1234;   // 常量在定义的时候必须初始化
    const int number[] = {1, 2, 3, 4};
//    number[1] = 50; error
    const int *p = new int(100); // 常量指针通常在声明的时候初始化
    cout << *p << endl;
    char str[] = "hello";
    const char *p_str = str; // 指向字符串的常量指针不允许修改字符
//    *p_str = 'a'; error
    cout << "p_str = " << p_str << endl;
    /**
     * 常量指针: 指针本身是常量，不允许在指向其它的内存空间，但指向的内存空间的数据可以修改
     */
    char *const p_str1 = str;
    *p_str1 = 'l';
//    p_str1 = new char[3]; error  p_str1 本身是常量，无法进行赋值
    cout << "===================================" << endl;

    struct MyStruct {
        int code;
        char *name; /* new 进行初始化的时候，只会分配指针的空间大小(8个bit) */
        double price;

    };
    auto *myStruct = new MyStruct();
    myStruct->name = new char[30];
    strcpy(myStruct->name, "hello world!");
    (*myStruct).code = 1;
    (*myStruct).price = 6999.9;

    cout << "(*myStruct).code = " << (*myStruct).code << endl;
    cout << "myStruct->name = " << myStruct->name << endl;
    cout << "(*myStruct).price = " << (*myStruct).price << endl;
    cout << "===================================" << endl;

    union MyUnion {
        int code1;
        long code2;
    };

    auto *myUnion = new MyUnion();
    myUnion->code1 = 100;
    cout << "myUnion->code1 = " << myUnion->code1 << endl;
    cout << "myUnion->code2 = " << myUnion->code2 << endl;

    myUnion->code2 = 400;
    cout << "myUnion->code1 = " << myUnion->code1 << endl;
    cout << "myUnion->code2 = " << myUnion->code2 << endl;

    return 0;
}
