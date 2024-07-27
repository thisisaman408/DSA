/*
    Here, the question is, you are given a number n, you have some operations you can do on it, any no of time
    1) reduce it by 1, -> n = n -1;
    2) if n %2 == 0, so n = n/2;
    3) if n%3 ==0, so make n = n/3;
*/

#include <iostream>
#include <vector>
using namespace std;
// this is greedy approch, which is wrong, for 10, for 10 it will give 4, but the ans is 3 10->9->3->1
int greedyReduceToOne(int n, int count)
{
    if (n == 1)
        return count;
    else if (n % 2 == 0)
    {
        count++;
        return greedyReduceToOne(n / 2, count);
    }
    else if (n % 3 == 0)
    {
        count++;
        return greedyReduceToOne(n / 3, count);
    }
    else
    {
        count++;
        return greedyReduceToOne(n - 1, count);
    }
}
#define inf INT_MAX
int reduceToOne(int n)
{
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;

    return 1 + min({reduceToOne(n - 1), (n % 2 == 0) ? reduceToOne(n / 2) : inf, (n % 3 == 0) ? reduceToOne(n / 3) : inf});
}

vector<int> dp;
int reduceToOneDP(int n)
{
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (dp[n] != -1)
        return dp[n]; // this nth state is precomputed

    return dp[n] = 1 + min({reduceToOne(n - 1), (n % 2 == 0) ? reduceToOne(n / 2) : inf, (n % 3 == 0) ? reduceToOne(n / 3) : inf});
}

int reduceToOneDPT(int n)
{
    //O(n) time, O(n) space
    dp.clear();
    dp.resize(n + 1, -1);
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        //just copied the memoization technique, and gave the order, so in tabulation just need to find the order, else is same(generally)
        dp[i] = 1 + min({dp[i - 1], (i % 2 == 0) ? dp[i / 2] : inf, (i % 3 == 0) ? dp[i / 3] : inf});
    }
    return dp[n];
}

int main()
{
    int n = 100;
    dp.clear();
    dp.resize(n + 1, -1);
    cout << "Greedy Approach : " << greedyReduceToOne(n, 0) << endl;
    // the below one is a non dp optimised normal recursion code
    cout << "Normal Recursion :  " << reduceToOne(n) << " " << endl;

    // the below one is a memoized code,
    cout << "Memoization : " << reduceToOneDP(n) << " " << endl;
    // the below one is a tabulation code, dp
    cout << "Tabulation : " << reduceToOneDPT(n) << " " << endl;
}