//
// Created by miclefengzss on 2018/2/1.
//

#include <iostream>

using namespace std;

int main()
{
    int carrots;
    cout << "How many carrots do you have?" << endl;
    cin >> carrots;
    cout << "Here are two." << endl;
    carrots = carrots + 2;
    cout << "Now you have " << carrots  << " carrots." << endl;
    return 0;
}

//result :
//How many carrots do you have?
//5    cin
//5
//Here are two.
//N
//
//Now you have 7 carrots.