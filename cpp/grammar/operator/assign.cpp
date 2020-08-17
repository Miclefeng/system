//
// Created by miclefengzss on 2018/2/13.
//

#include <iostream>

using namespace std;

int main ()
{
    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tree = 3;
    int guess = 3.923;
    int debt = 2.14e9;
    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;
    return 0;
}


