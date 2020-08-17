//
// Created by miclefengzss on 2018/1/26.
//

#include <iostream>
#include "windows.h"

using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    auto name = "hankcs";
    cout << name << endl;
    MessageBox(NULL, "Hello World!", "Caption", MB_OK);
    return 0;
}