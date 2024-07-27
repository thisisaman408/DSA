#include <iostream>
using namespace std;
int display(int n, int arr[], int idx)
{
    if (idx == n)
    {

        return INT_MIN;
    }
    return max(arr[idx], display(n, arr, idx + 1));
}

int main()
{
    int n;
    int arr[] = {3, 4, 2, 5, 2, 4, 2, 12, 32, 32, 21};
    n = sizeof(arr) / sizeof(arr[0]);
    int p = display(n, arr, 0);
    cout << p << endl;
}