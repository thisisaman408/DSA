#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in sorted order : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int p;
    cout << "Enter the element whose first occurence is to be calucalated : ";
    cin >> p;
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (p == arr[mid])
        {
            if (arr[mid - 1] == p)
            {
                hi = mid - 1;
            }
            else
            {
                cout << mid;
                break;
            }
        }
        else if (arr[mid] < p)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return -1;
}