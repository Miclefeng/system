//
// Created by miclefengzss on 2018/2/2.
//

#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << "Int is " << sizeof(n_int) << " bytes." << endl;
    cout << "Short is " << sizeof(n_short) << " bytes." << endl;
    cout << "Long is " << sizeof(n_long) << " bytes." << endl;
    cout << "Long long is " << sizeof(n_llong) << " bytes." << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "Int : " << n_int << endl;
    cout << "Short : " << n_short << endl;
    cout << "Long : " << n_long << endl;
    cout << "Long long : " << n_llong << endl;
    cout << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
    return 0;
}

//result:
//Int is 4 bytes.
//Short is 2 bytes.
//Long is 4 bytes.
//Long long is 8 bytes.
//
//Maximum values:
//Int : 2147483647
//Short : 32767
//Long : 2147483647
//Long long : 9223372036854775807
//
//Minimum int value = -2147483648
//Bits per byte = 8