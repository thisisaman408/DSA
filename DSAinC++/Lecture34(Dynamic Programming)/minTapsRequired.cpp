/*
https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
*/

#include <iostream>
#include <vector>

using namespace std;

#define ll long long
class Solution
{
public:
    int minTaps(int n, vector<int>ranges)
    {
        vector<ll> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++)
        {
            int start = max(0, i - ranges[i]);
            int end = min(i + ranges[i], n);
            ll ans = INT_MAX;
            for (int j = start; j <= end; j++)
            {
                ans = min(ans, dp[j]);
            }
            if (ans != INT_MAX)
            {
                dp[end] = min(ans + 1, dp[end]);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};

int main(){

    Solution sol;
    vector<int> ranges = {3,4,1,1,0,0};
    int n = 5;

    cout<<sol.minTaps(5,ranges)<<endl;
}
