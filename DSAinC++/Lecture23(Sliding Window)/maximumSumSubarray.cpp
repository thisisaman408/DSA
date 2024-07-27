#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {7, 1, 2, 5, 8, 4, 9, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    // return the max sum of the subarray of size 3 from arr,
    int maxSum = 0;
    int idx = 0;
    for (int i = 0; i <= n - k; i++)
    {
        int sum = 0;
        for (int j = i; j < i + k; j++)
        {
            sum += arr[j];
        }
        maxSum = max(sum, maxSum);
        if (maxSum == sum)
            idx = i;
    }
    for (int p = idx; p < (idx + k); p++)
    {
        cout << arr[p] << " ";
    }
    cout << endl;
    cout << maxSum;
}
// maximum sum subarray of size k