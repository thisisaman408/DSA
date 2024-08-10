#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum = 0;
int temp;
int countA = 1, countB = 1, countC = 1;
//this solution is wrong
//use bottom up approach for it, as done in main function
int f(int n, vector<vector<int>> &h)
{
    for (int i = 0; i < n; i++)
    {

        temp = max({h[i][0], h[i][1], h[i][2]});
        if (temp == h[i][0])
        {
            countA++;
            cout << "A : " << countA << " ";
            if (countA <= 2)
                sum += h[i][0];
            cout << sum << " ";

            countB = 0;
            countC = 0;
        }
        if (temp == h[i][1])
        {
            countB++;
            cout << "B :" << countB << " ";
            if (countB <= 2)
                sum += h[i][1];
            cout << sum << " ";
            countA = 0;
            countB = 0;
        }
        if (temp == h[i][2])
        {
            countC++;
            cout << "C :" << countC << " ";
            if (countC <= 2)
                sum += h[i][2];
            cout << sum << " ";
            countA = 0;
            countB = 0;
        }
    }
    return sum;
}

int main()
{
    int n;
    cin >> n; // no of days

    vector<vector<int>> dp(n, vector<int>(3, 0));

    int a, b, c;
    cin >> a >> b >> c;

    dp[0][0] = a;
    dp[0][1] = b;
    dp[0][2] = c;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;

        dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = c + max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}