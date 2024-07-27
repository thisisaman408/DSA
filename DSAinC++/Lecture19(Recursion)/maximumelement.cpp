#include <iostream>
using namespace std;
void display(int n, int arr[], int idx, int max)
{
    if (idx == n)
    {
        cout << max;
        return;
    }
    if (arr[idx] > max)
    {
        max = arr[idx];
    }

    display(n, arr, idx + 1, max);
}

int printmax(int arr[], int n, int idx)
{
    if (idx == n)
    {
        return INT_MIN;
    }
    return max(arr[idx], printmax(arr, n, idx + 1));
}

int main()
{
    int n;
    int arr[] = {3, 4, 2, 5, 2, 4, 2, 12, 32, 32, 21};
    n = sizeof(arr) / sizeof(arr[0]);
    display(n, arr, 0, INT_MIN);
    cout << endl;
    cout << printmax(arr, n, 0) << " ";
}