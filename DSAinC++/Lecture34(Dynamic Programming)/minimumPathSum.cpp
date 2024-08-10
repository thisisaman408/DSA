// https://leetcode.com/problems/minimum-path-sum/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &dp)
    {
        int m = dp.size();
        int n = dp[0].size();
        for (int i = n - 2; i >= 0; i--)
        {
            dp[m - 1][i] += dp[m - 1][i + 1];
        }
        for (int i = m - 2; i >= 0; i--)
        {
            dp[i][n - 1] += dp[i + 1][n - 1];
        }
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                dp[i][j] = dp[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[0][0];
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> dp = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << sol.minPathSum(dp) << endl;
    return 0;
}