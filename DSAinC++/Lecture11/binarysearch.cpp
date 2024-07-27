#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter size of your array : " << endl;
    cin >> size;
    int arr[size];
    int n;
    int low = 0;
    int high = size;
    int mid = (low + high) / 2;
    cout << "Enter the elements of array : " << endl;
    for (int i = 0; i <= size - 1; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element you want to search for : " << endl;
    cin >> n;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == n)
        {
            cout << mid;
            break;
        }
        else if (arr[mid] > n)
        {
            high = mid - 1;
        }
        else if (arr[mid] < n)
        {
            low = mid + 1;
        }
    }
}