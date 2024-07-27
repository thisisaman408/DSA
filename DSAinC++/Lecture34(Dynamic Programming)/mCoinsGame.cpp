/*

Asen and Boyan are playing the following game. They choose two different positive integers K and L, and start the game with a tower of N coins. Asen always plays first, Boyan – second, after that – Asen again, then Boyan, and so on. The boy in turn can take 1, K or L coins from the tower. The winner is the boy, who takes the last coin (or coins). After a long, long playing, Asen realizes that there are cases in which he could win, no matter how Boyan plays. And in all other cases Boyan being careful can win, no matter how Asen plays.

So, before the start of the game Asen is eager to know what game case they have. Write a program coins which help Asen to predict the game result for given K, L and N.

INPUT
The input describes m games.

The first line of the standard input contains the integers K, L and m, 1 < K < L < 10, 3 < m < 50. The second line contains m integers N1, N2 … Nm, 1 ≤ Ni ≤ 1 000 000, i = 1, 2 … m, representing the number of coins in each of the m towers




https://www.spoj.com/problems/MCOINS/
*/

#include <iostream>
#include <vector>

using namespace std;

int f(int n, int k, int l, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 1 || n == k || n == l)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = !(f(n - 1, k, l, dp) and (n - k >= 1 ? f(n - k, k, l, dp) : 1) and (n - l >= 1 ? f(n - l, k, l, dp) : 1));
    return dp[n];
}

int main()
{
    int k, l, m;
    cin >> k >> l >> m;
    // m is no of coins

    vector<int> dp(1000005, -1);

    // dp[1] = 1;
    // dp[k] = 1;
    // dp[l] = 1;
    // for (int i = 2; i <= 1000000; i++)
    // {
    //     if (i == k || i == l)
    //         continue;
    //     dp[i] = !(dp[i - 1] and (i - k >= 1 ? dp[i - k] : 1) and (i - l >= 1 ? dp[i - l] : 1));
    // }

    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        if (f(n, k, l, dp) == 1)
            cout << "A";
        else
            cout << "B";
    }
}