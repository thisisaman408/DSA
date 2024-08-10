// https://leetcode.com/problems/unique-paths-ii/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int helper(int m, int n, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (m < 0 || n < 0 || arr[m][n] == 1)
            return 0;
        if (m == 0 && n == 0)
            return 1; // it means we are at 0 0
        if (dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = helper(m, n - 1, arr, dp) + helper(m - 1, n, arr, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(m - 1, n - 1, obstacleGrid, dp);
    }
};

int main()
{

    Solution sol;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << sol.uniquePathsWithObstacles(obstacleGrid);
}