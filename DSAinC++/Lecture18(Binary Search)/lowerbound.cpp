#include <iostream>
using namespace std;
void swap(int *m, int *n)
{
    int temp = *m;
    *m = *n;
    *n = temp;
}
void bubblesort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }
        if (flag == true)
        {
            break;
        }
    }
}
void printarray(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubblesort(n, arr);
    int x;
    cout << "Enter the element whose lower bound you want to calculate:";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
        {
            cout << "The lower bound is " << arr[i - 1];
            break;
        }
    }
}
