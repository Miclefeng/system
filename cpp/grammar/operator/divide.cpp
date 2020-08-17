//
// Created by miclefengzss on 2018/2/12.
//

#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Integer division: 9/5 = " << 9/5 << endl;
    cout << "Floating-point division: 9.0/5.0 = ";
    cout << 9.0/5.0 << endl;
    cout << "Mixed division: 9.0/5 = " << 9.0/5 << endl;
    cout << "Double constants: 1.e7/9.0 = " << 1.e7/9.0 << endl;
    cout << "Float constants: 1.e7f/9.0f = " << 1.e7f/9.0f << endl;
    return 0;
}
