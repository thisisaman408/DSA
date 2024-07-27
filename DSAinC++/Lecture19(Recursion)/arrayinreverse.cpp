#include <iostream>
using namespace std;
void imp(int arr[], int n, int index)
{
    if (index < 0)
        return;
    cout << arr[index];
    imp(arr, n, index - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    imp(arr, 7, 6);
}
/*
 */