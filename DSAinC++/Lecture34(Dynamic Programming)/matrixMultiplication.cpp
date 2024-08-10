/*
An array is given which is representing the dimensions of a matrix, r*c, in array arr (say)
the dimension of ith matrix is [arr[i-1]*arr[i]];

your task is to find the most efficient way to to multiply these matrices together such that the total

number of element multiplication is minimum.

Here, how to calculate the no of multiplication in a matrix??


consider a matrix

A(3*3) = 1 2 3
         4 5 6
         7 8 9
B(3*2) = 10 11
         12 13
         14 15

i want to multiply them, 1*10 + 2*12 + 3*14       1*11 + 2* 13 + 3*15
                         4*10 + 5*12 + 6*14       4*11 + 5*13 + 6*15
                         7*10 + 8*12 + 9*14       7*11 + 8*13 + 9*15


how many multiplications, did we do?? 18, yes?

now, actually there is a formula for it, which is,
for example, there are two matrices say, which are going to be multipled
example n*m and m*k, ofcourse the columns of first and rows of second must be say for being eligile for matrix multiplication,
here, if we just do n*m*k, this will give is the no of multiplication are done in this multiplication

in our above example, it is 3*3, and 3*2, so 3*3*2 = 18, so we do not have to calculate it, we can do it by this only

so now the task of this question is, we have to mulitply these matrices in such order, such that, this elemental multiplication is minimum.

Got it??

Now first give it a try,

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int>> dp;

int f(int i, int j, vector<int> &arr)
{
    if (i == j || i + 1 == j)
        return 0;
    int res = INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int k = i + 1; k < j; k++)
    {
        res = min(res, f(i, k, arr) + f(k, j, arr) + arr[i] * arr[j] * arr[k]);
        // partition banaye hain k se, i se lekar k tak ka ans, k se lekr j tak ka ans, and then ye dono (i-k) & (k-j) tak ki matrix
        //  mai v to milkar ek matrix banegi, unke element muliplication hoga, arr[i]arr[j]arr[k];
    }

    return dp[i][j] = res;
}

int main()
{

    int n;
    cin >> n;
    dp.clear();
    dp.resize(1005, vector<int>(1005, -1));

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // We should initialize dp[i][i] to 0 because the cost of multiplying one matrix is zero.
    // for (int i = 0; i < n; i++)
    //     dp[i][i] = 0;

    // // Calculate dp values for chains of length 3 to n
    // for (int len = 3; len <= n; len++)
    // {
    //     for (int i = 0; i <= n - len; i++)
    //     {
    //         int j = i + len - 1;
    //         dp[i][j] = INT_MAX; // Initialize to a large value for minimization
    //         for (int k = i + 1; k < j; k++)
    //         {
    //             dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[j] * v[k]);
    //         }
    //     }
    // }

    // // Output the minimum cost to multiply matrices from the first to the last
    // cout << dp[0][n - 1] + 4 << endl;
    cout << f(0, n - 1, v);
}