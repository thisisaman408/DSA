/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.

https://cses.fi/problemset/task/1633

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> dp(1000006, INT_MIN);
#define mod 1000000007
int f(int n)
{
    if (n == 0)
        return 1;
    if (dp[n] != INT_MIN)
        return dp[n];
    int sum = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (n - i < 0)
            break;
        sum = (sum % mod + f(n - i) % mod) % mod;
    }
    return dp[n] = sum;
}

int f2(int n)
{
    dp[0] = 1;
    for (int k = 1; k <= n; k++)
    {
        int sum = 0;
        for (int i = 1; i <= 6; i++)
        {
            if (k - i < 0)
                break;
            sum = (sum % mod + dp[k - i] % mod) % mod;
        }
        dp[k] = sum % mod;
    }
    return dp[n];
}

int main()
{
    dp.clear();
    int n;
    cin >> n;
    cout << f(n) << endl;
    cout << f2(n) << endl;
}