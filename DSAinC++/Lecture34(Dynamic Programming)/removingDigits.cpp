/*
it is recommended to solve cses problems
https://cses.fi/problemset/

this is the link,

today I a solving, one of the problem , removing digits
*/

/*
    You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.
Constraints

1 \le n \le 10^6

Example
Input:
27

Output:
5

Explanation: An optimal solution is 27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> getDigits(int n)
{
    vector<int> result;
    while (n > 0)
    {
        if (n % 10 != 0)
        {
            result.push_back(n % 10);
        }
        n /= 10;
    }
    return result;
}
int removeDigits(int n)
{
    if (n == 0)
        return 0;
    if (n <= 9)
        return 1;
    int result = INT_MAX;
    vector<int> d = getDigits(n);
    for (int i = 0; i < d.size(); i++)
    {
        result = min(result, removeDigits(n - d[i]));
    }
    return 1 + result;
}
vector<int> dp;
int removeDigitss(int n)
{
    if (n == 0)
        return 0;
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int result = INT_MAX;
    vector<int> d = getDigits(n);
    for (int i = 0; i < d.size(); i++)
    {
        result = min(result, removeDigits(n - d[i]));
    }
    return dp[n] = 1 + result;
}
int main()
{
    int n;
    cin >> n;
    dp.clear();
    dp.resize(1000006, -1);
    cout << "Recursive :" << removeDigits(n) << " " << endl;
    cout << "Memoized  :" << removeDigitss(n) << " " << endl;
}