#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[] = {1, 2, 4, 6, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
}