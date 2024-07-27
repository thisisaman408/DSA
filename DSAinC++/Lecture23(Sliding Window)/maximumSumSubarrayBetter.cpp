// implementing the problem using sliding window
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {7, 1, 2, 5, 8, 4, 9, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int i = 1;
    int j = k;
    int maxSum = INT_MIN;
    int sum = 0;
    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    maxSum = sum;
    while (j < n)
    {
        sum = sum + arr[j++] - arr[i - 1];
        if (maxSum < sum)
        {
            maxSum = sum;
            idx = i;
        }
        i++;
    }
    cout << idx << endl;
    for (int i = idx; i < idx + k; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << maxSum;
}