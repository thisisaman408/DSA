/*

dp is just recursion with some memoization and tabulation techniques, meaning just
using some modifications in the current approaches, (recursion hi hai, memoization m).
*/
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int fib(int n)
    {
        // this is tabulation, or iterative dp, or bottom top approach dp, also called real dp
        if (n <= 1)
            return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int fibo(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
    }
};

int main()
{
    Solution sol;
    int n = 10;
    vector<int> dp(n + 1, -1);
    cout << sol.fib(n) << endl;
    cout << sol.fibo(n, dp) << " ";
}