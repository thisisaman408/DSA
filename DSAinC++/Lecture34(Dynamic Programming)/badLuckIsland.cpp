/*

The Bad Luck Island is inhabited by three kinds of species: r rocks, s scissors and p papers. At some moments of time two random individuals meet (all pairs of individuals can meet equiprobably), and if they belong to different species, then one individual kills the other one: a rock kills scissors, scissors kill paper, and paper kills a rock. Your task is to determine for each species what is the probability that this species will be the only one to inhabit this island after a long enough period of time.

Input
The single line contains three integers r, s and p (1 ≤ r, s, p ≤ 100) — the original number of individuals in the species of rock, scissors and paper, respectively.

Output
Print three space-separated real numbers: the probabilities, at which the rocks, the scissors and the paper will be the only surviving species, respectively. The answer will be considered correct if the relative or absolute error of each number doesn't exceed 10 - 9.


https://codeforces.com/problemset/problem/540/D

*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string.h>
using namespace std;

double dp[105][105][105];
double f3(int r, int s, int p)
{
    if (r == 0)
        return 1;
    if (p == 0)
        return 0;
    if (s == 0)
        return 0;
    if (dp[r][s][p] > -0.9)
        return dp[r][s][p];
    return dp[r][s][p]  = f3(r, s - 1, p) * (r * s) / (r * s + s * p + r * p) + f3(r - 1, s, p) * (r * p) / (r * s + s * p + r * p) + f3(r, s, p - 1) * (s * p) / (r * s + s * p + r * p);
}
double f2(int r, int s, int p)
{
    if (r == 0)
        return 0;
    if (p == 0)
        return 0;
    if (s == 0)
        return 1;
    if (dp[r][s][p] > -0.9)
        return dp[r][s][p];
    return dp[r][s][p] = f2(r, s - 1, p) * (r * s) / (r * s + s * p + r * p) + f2(r - 1, s, p) * (r * p) / (r * s + s * p + r * p) + f2(r, s, p - 1) * (s * p) / (r * s + s * p + r * p);
}
double f1(int r, int s, int p)
{
    if (r == 0)
        return 0;
    if (p == 0)
        return 1;
    if (s == 0)
        return 0;
    if (dp[r][s][p] > -0.9)
        return dp[r][s][p];
    return dp[r][s][p] = f1(r, s - 1, p) * (r * s) / (r * s + s * p + r * p) + f1(r - 1, s, p) * (r * p) / (r * s + s * p + r * p) + f1(r, s, p - 1) * (s * p) / (r * s + s * p + r * p);
}
int main()
{
    int r, s, p;
    memset(dp, -1, sizeof(dp));
    cin >> r >> s >> p;
    double ans1 = f1(r, s, p); // for rock
    memset(dp, -1, sizeof(dp));
    double ans2 = f3(r, s, p); // for paper
    memset(dp, -1, sizeof(dp));
    double ans3 = f2(r, s, p); // for scissor
    vector<double> q(3, 0);
    q[0] = ans1;
    q[1] = ans2;
    q[2] = ans3;
    for (int i = 0; i < 3; i++)
        cout << fixed << setprecision(9) << q[i] << " ";
    cout << endl;
    return 0;
}
