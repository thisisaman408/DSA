#include <iostream>
#include <vector>
using namespace std;
int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    vector<int> suffix(nums);
    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] += suffix[i + 1];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << suffix[i] << " ";
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == suffix[i])
            return i;
    }
    return -1;
}
int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    pivotIndex(nums);
}