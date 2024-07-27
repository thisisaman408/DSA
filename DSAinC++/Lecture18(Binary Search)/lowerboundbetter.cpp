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
    cout << "Enter the element whose lower bound is to calculate : ";
    cin >> p;
    int lo = 0;
    int hi = n - 1;
    bool flag = false;
    // always use lo <= hi, not lo < hi
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == p)
        {
            flag = true;
            cout << arr[mid - 1];//for upper bound just make it mid + 1
            break;
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
    if (flag == false)
    {
        cout << arr[hi]; // for upper bound, just print lo,instead of hi
    }
}