//
// Created by miclefengzss on 2018/2/5.
//

#include <iostream>

using namespace std;

int main()
{
    char ch = 'M';
    int i = ch;
    cout << "The ASCII code for M " << "is " << i << endl;
    ch = ch + 1;
    i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;
    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);
    cout << endl;
    cout << '$';
    cout << endl;
    cout.put('$');
    cout << endl;
    cout << '\n'; // character constant
    cout << "\n22"; // string
    return 0;
}

//result :
//The ASCII code for M is 77
//The ASCII code for N is 78
//Displaying char ch using cout.put(ch): N
//$
//$
//
//
//22