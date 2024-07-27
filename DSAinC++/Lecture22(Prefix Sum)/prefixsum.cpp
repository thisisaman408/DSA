#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixSum(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); ++i)
        nums[i] += nums[i - 1];
    return nums;
}
int main()
{
    vector<int> nums = {4, 2, 7, 8, 1, 12, 34, 78};
    nums = prefixSum(nums);
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
}