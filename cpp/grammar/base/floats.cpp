//
// Created by miclefengzss on 2018/2/12.
//

#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;
    const float MILLION = 1.0e6;
    float a = 2.34e22f;
    float b = a + 1.0f;

    cout << "tub = " << tub;
    cout << ", a million tubs = " << MILLION * tub;
    cout << ",\nand ten million tubs = " << 10 * MILLION * tub << endl;
    cout << "mint = " << mint << " and a million mints = ";
    cout << MILLION * mint << endl;
    cout << "a = " << a << endl;
    cout << "b - a = " << b - a << endl;
    return 0;
}


