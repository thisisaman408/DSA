/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
Constraints

1 < n < 100

1 < x < 10^6
1 < c[i] < 10^6

https://cses.fi/problemset/task/1634


*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> coins;
vector<int> dp(1000006, INT_MIN);
// similar question as reduce to 1, or removing digits, same logic
int f(int x)
{
    if (x == 0)
        return 0;
    if (dp[x] != INT_MIN)
        return dp[x];
    int result = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if (x - coins[i] < 0)
            continue;
        result = min(result, f(x - coins[i]));
    }
    if (result == INT_MAX)
        return dp[x] = INT_MAX;
    return dp[x] = 1 + result;
}

int f2(int x)
{
    dp.resize(x + 1, INT_MAX); // Resize the dp array to x+1 and initialize all values to INT_MAX
    dp[0] = 0;                 // Base case: It takes 0 coins to make the sum 0

    for (int i = 1; i <= x; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[x];
}

int main()
{
    dp.clear();
    int n, x;
    cin >> n; // no of coins
    cin >> x; // sum required
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        coins.push_back(num);
    }
    int ans = f(x);
    if (ans == INT_MAX)
        cout << "-1" << endl;
    else
        cout << ans << endl;
    int ans2 = f2(x);
    if (ans2 == INT_MAX)
        cout << "-1" << endl;
    else
        cout << ans2 << endl;

    return 0;
}