// https://atcoder.jp/contests/dp/tasks/dp_l?lang=en

/*

Problem Statement
Taro and Jiro will play the following game against each other.

Initially, they are given a sequence
a=(a
1
​
 ,a
2
​
 ,…,a
N
​
 ). Until
a becomes empty, the two players perform the following operation alternately, starting from Taro:

Remove the element at the beginning or the end of
a. The player earns
x points, where
x is the removed element.
Let
X and
Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize
X−Y, while Jiro tries to minimize
X−Y.

Assuming that the two players play optimally, find the resulting value of
X−Y.

*/

#include <iostream>
#include <vector>
#include <cstring>
#define ll long long

using namespace std;

vector<vector<ll>> dp(3005, vector<ll>(3005, -1));
vector<ll> arr(3005);
ll f(int i, int j)
{
    if (i == j) return arr[i];
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(arr[i] - f(i + 1, j), arr[j] - f(i, j - 1));
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << f(0, n - 1);
}

int main()
{
    int n;
    cin >> n;
    dp.clear();

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) dp[i][i] = arr[i];

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
}
