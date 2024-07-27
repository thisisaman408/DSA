#include <vector>
#include <climits>
#include<iostream>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int coin : coins)
    {
        for (int i = coin; i <= amount; ++i)
        {
            if (dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
int main()
{
    vector<int> arr = {1,2,5};
    int amount = 11;
    cout<<coinChange(arr,amount);

}