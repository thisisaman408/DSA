#include <iostream>
using namespace std;
void print(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void heapify(int i, int arr[], int n)
{
    while (1)
    {
        int l = 2 * i, r = 2 * i + 1;
        if (l >= n)
            break;
        if (r >= n)
        {
            if (arr[i] > arr[l])
                swap(arr[i], arr[l]);
            break;
        }
        if (arr[l] < arr[r] && arr[i] > arr[l])
        {
            swap(arr[i], arr[l]);
            i = l;
        }
        else if (arr[r] < arr[l] && arr[i] > arr[r])
        {
            swap(arr[i], arr[r]);
            i = r;
        }
        else
            break;
    }
}

int main()
{
    int arr[] = {-1, 10, 2, 14, 11, 1, 4};
    int n = sizeof(arr) / 4;
    print(arr, n);
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(i, arr, n);
    }
    print(arr, n);
}