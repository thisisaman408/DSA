#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/unique-binary-search-trees/
vector<int> dp;
class Solution
{
public:
    int f(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (dp[n] != -1)
            return dp[n];
        int sum = 0;
        for (int k = 1; k <= n; k++)
            sum += f(k - 1) * f(n - k);
        return dp[n] = sum;
    }
    int numTrees(int n)
    {
        dp.clear();
        dp.resize(21, -1);
        return f(n);
    }
};

int main()
{
    dp.clear();
    dp.resize(21,-1);
    Solution sol;
    int n = 3;
    cout << sol.f(n);
}

//this problem is based on CATALIN NUMber

//https://cp-algorithms.com/combinatorics/catalan-numbers.html learn about catalan number from here