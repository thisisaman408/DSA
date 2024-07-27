#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 13, 43, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << size;
}