//
//  main.cpp
//  pointer
//
//  Created by miclefengzss on 2020/11/29.
//

#include <iostream>
#include <vector>
#include <array>

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

    int *arr;
    arr = new int[10];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    delete[] arr;

    arr = new int[20];
    arr[0] = 10;
    arr[1] = 11;

    cout << "array[0] = " << arr[0] << endl;
    cout << "array[1] = " << arr[1] << endl;
    cout << "array[2] = " << *(arr + 2) << endl;
    delete[] arr;
    arr = nullptr;
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
    cout << "===================================" << endl;

    vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    for (int v : values) {
        cout << v << endl;
    }
    cout << "values size: " << values.size() << endl;
    values.pop_back();
    cout << "pop_back() after: " << endl;
    for (int v : values) {
        cout << v << endl;
    }
    cout << "remove first after: " << endl;
    values.erase(values.begin());
    for (int v : values) {
        cout << v << endl;
    }
    cout << "values.at(0) = " << values.at(0) << endl;
    cout << "===================================" << endl;


    // 数组模板(c++ 11)
    /**
     * 数组模板和数组的区别
     * 1. 数组和数组模板在后期初始化的时候不同
     * 2. 数组的大小可以使用变量，数组模板的大小不能使用变量，可以使用常量
     * 3. 数组有时候可以当做指针使用，数组模板不可以
     * 4. 将数组赋值给指针是引用复制，数组模板之间赋值是值复制
     */
    const int size = 5;
    array<string, size> productNames = {"mate", "iphone"};
    array<int, 3> codes1{};
    codes1 = {1, 2, 3};
    int codes3[3];
    codes3[0] = 66;
    // codes = {1,2,3}; error
    cout << "productNames[0] = " << productNames[0] << endl;
    if (productNames[4].empty()) {
        cout << "productNames[4] = \"\"" << endl;
    }

    array<int, 3> codes2{};
    codes2 = codes1;
    codes2[0] = 33;
    cout << "codes1[0] = " << codes1[0] << endl;
    cout << "codes2[0] = " << codes2[0] << endl;

    int *pCode = codes3;
    pCode[0] = 22;

    cout << "codes3[0] = " << codes3[0] << endl;
    cout << "pCode[0] = " << pCode[0] << endl;
    return 0;
}
