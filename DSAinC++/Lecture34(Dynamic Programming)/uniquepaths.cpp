// https://leetcode.com/problems/unique-paths/

#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // tabulation
        vector<vector<int>> nums(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            nums[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            nums[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                nums[i][j] = nums[i - 1][j] + nums[i][j - 1];
            }
        }
        return nums[m - 1][n - 1];
    }

    int helper(int m, int n, vector<vector<int>> &dp)
    {
        if (m == 1 && n == 1)
            return 1;
        if (m < 1 || n < 1)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        dp[m][n] = helper(m - 1, n, dp) + helper(m, n - 1, dp);
        return dp[m][n];
    }
    int uniquePathss(int m, int n)
    // memoization
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(m, n, dp);
    }
};
int main()
{
    Solution sol;
    int m = 3;
    int n = 7;
    cout << sol.uniquePaths(m, n) << " " << sol.uniquePathss(m, n) << endl;
    m = 3, n = 2;
    cout << sol.uniquePaths(m, n) << " " << sol.uniquePathss(m, n) << endl;
}
