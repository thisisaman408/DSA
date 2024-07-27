/*
check if we can partition a array into two parts such the sum of the elements in both the part is same
*/

#include <iostream>
using namespace std;

bool partition(int nums[], int n)
{
    for (int i = 1; i < n; ++i)
        nums[i] += nums[i - 1];
    for (int i = 0; i < n; i++)
    {
        if (2 * nums[i] == nums[n - 1])
        {
            cout << i << " ";
            return true;
        }
    }
    return false;
}
int main()
{
    int arr[] = {1, 7, 3, 6, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << partition(arr, n);
}