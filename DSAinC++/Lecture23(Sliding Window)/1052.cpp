#include <iostream>
#include <vector>
using namespace std;

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int n = customers.size();
    int k = minutes;
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        sum += customers[i];
    }
    cout << sum;
    cout << endl;
    int idx = 0;
    int i = 1;
    int j = k;
    maxSum = sum;
    while (j < n)
    {
        sum = sum + customers[j++] - customers[i - 1];
        if (maxSum < sum)
        {
            maxSum = sum;
            idx = i;
        }
        i++;
    }
    cout << idx;
    cout << endl;
    for (int i = idx; i < (idx + k); i++)
    {
        grumpy[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << grumpy[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << customers[i] << " ";
    }
    cout << endl;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (grumpy[i] == 0)
        {
            sum += customers[i];
        }
    }
    return sum;
}
int main()
{
    vector<int> arr = {4,10,10};
    vector<int> arr1 = {1,1,0};
    int amount = 2;
    cout << maxSatisfied(arr, arr1, amount);
}