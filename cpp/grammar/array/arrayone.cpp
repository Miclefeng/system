//
// Created by miclefengzss on 2018/2/13.
//

#include <iostream>

using namespace std;

int main ()
{
    int yams[3] = {7, 8, 6};
    int yamcosts[3];
    yamcosts[0] = 20;
    yamcosts[1] = 30;
    yamcosts[2] = 5;

    cout << "Size of yams array = " << sizeof(yams) << " bytes.\n";
    cout << "Size of one element = " << sizeof(yams[0]) << " bytes.\n";
    return 0;
}
