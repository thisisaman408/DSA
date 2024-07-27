// https://leetcode.com/problems/min-cost-climbing-stairs/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // this is memoization
    int helper(vector<int> cost, int i, vector<int> &dp)
    {
        if (i == 0 || i == 1)
            return cost[i];
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = cost[i] + min(helper(cost, i - 1, dp), helper(cost, i - 2, dp));
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(helper(cost, n - 1, dp), helper(cost, n - 2, dp));
    }

    // this is tabulation

    int minCostClimbingStairss(vector<int> &cost)
    {
        // tabulation dp

        for (int i = 2; i < cost.size(); i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};
int main()
{
    Solution sol;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << sol.minCostClimbingStairs(cost) << " " << sol.minCostClimbingStairss(cost);
    cout << endl;
    cost = {10, 15, 20};
    cout << sol.minCostClimbingStairs(cost) << " " << sol.minCostClimbingStairss(cost);
}

/*
It is really important to understand whether a question can be solved using greedy
or it needs dp, this will come with experience



Whenever, converting a recursive solution to memoization, try to go from n to 1 or 0
 */
