//
// Created by miclefengzss on 2018/2/24.
//

#include <iostream>

using namespace std;

int main()
{
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    char name2[ArSize];
    char dessert2[ArSize];

    // cin 使用空白(空格、制表符和换行符)来确定字符串的结束位置
//    cout << "Enter your name:\n";
//    cin >> name;
//    cout << "Enter your favorite dessert:\n";
//    cin >> dessert;
//    cout << "I have some delicious " << dessert;
//    cout << " for you, " << name << ".\n";
//    cout << endl;

    // getline(string, size) 获取整行输入
    cout << "Enter your name:\n";
    cin.getline(name2, ArSize);
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert2, ArSize);
    cout << "I have some delicious " << dessert2;
    cout << " for you, " << name2 << ".\n";

    return 0;
}


