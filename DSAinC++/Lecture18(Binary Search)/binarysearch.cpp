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
int binarysearch(int n, int arr[], int target)
{
    int low = 0;
    int high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{

    cout << "Enter the no of elements in the array ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter your elements";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Your array is : ";
    printarray(n, arr);
    cout << "Enter the element you want to search in the array : ";
    int target;
    cin >> target;
    bubblesort(n, arr);
    int x = binarysearch(n, arr, target);
    if (x == -1)
    {
        cout << "No such element found";
    }
    else
    {
        cout << "Your index of the required element is " << x;
    }
}

// time complexity of binary search is O(logn)