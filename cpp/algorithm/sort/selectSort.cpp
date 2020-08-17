//
// Created by miclefengzss on 2018/2/1.
//

#include <iostream>
#include <algorithm>

using namespace std;

void selectSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        int minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int arr[10] = {10, 9, 1, 3, 2, 5, 6, 4, 7, 8};
    int i;
    selectSort(arr, 10);
    for (i = 0; i < 10; i++) {
        if (9 == i) {
            cout << arr[i];
        } else {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;
    return 0;
}

//result:
//1, 2, 3, 4, 5, 6, 7, 8, 9, 10

