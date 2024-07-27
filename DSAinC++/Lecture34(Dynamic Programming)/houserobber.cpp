// https://leetcode.com/problems/house-robber/description/

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/

/*
first do not think, to calculate the odd index sum and even index sum, it is wrong
take this for example, {2,1,1,5} this is a test case of leetcode, here the max profite is
2 + 5 = 7, not 2 + 1 or 1+ 5, which is 3 and 6 respectively,

so basically, you have to use recursion, to iterate through the array, and then
calculate each subset, and then disregard all those arrays, in which there are adjacent elements


then at the end use memoization, to optimise it, this is the method and intiution to solve this
*/

/*

STATE OF DP : variable used in the problem of dp, or variables* by which we can identiy a
subproblem uniquely, that variable/variables is known as state of the dp
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // this is memoization or top down approach
    vector<int> dp;
    int helper(vector<int> &nums, int i)
    {
        if (i == nums.size() - 1)
            return nums[i];
        if (i == nums.size() - 2)
            return max(nums[i], nums[i + 1]);
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = max(nums[i] + helper(nums, i + 2), 0 + helper(nums, i + 1));
    }

    int rob(vector<int> &nums)
    {
        dp.clear();
        dp.resize(105, -1); /// max size is 100, so let's initialise it to 105, to avoid any upper bound etc issues
        return helper(nums, 0);
    }

    // this is tabulation

    int rob2(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        nums[n - 2] = max(nums[n - 1], nums[n - 2]);
        for (int i = n - 3; i >= 0; i--)
        {
            nums[i] = max(nums[i + 1], nums[i] + nums[i + 2]);
        }
        return nums[0];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 1, 1, 9};
    cout << sol.rob(nums) << " " << sol.rob2(nums) << endl;
}