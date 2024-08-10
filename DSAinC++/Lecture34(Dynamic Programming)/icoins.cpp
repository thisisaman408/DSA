/*

Let
N be a positive odd number.

There are
N coins, numbered
1,2,…,N. For each
i (
1≤i≤N), when Coin
i is tossed, it comes up heads with probability
p
i
​
  and tails with probability
1−p
i
​
 .

Taro has tossed all the
N coins. Find the probability of having more heads than tails.


https://atcoder.jp/contests/dp/tasks/dp_i
*/

#include <iostream>
#include <vector>
#include<iomanip>
//this header file is used to use a functino which is used to give an answer to some decimal place

using namespace std;
vector<vector<double>> dp(3000, vector<double>(1505,-1));


double f(vector<double>& coins, int i, int x){
    if(x == 0) return 1;
    if(i== -1) return 0;
    if(dp[i][x] > -0.9) return dp[i][x];// in float there might be some problems with ==, so use >
    return dp[i][x] = f(coins,i-1,x-1)*coins[i] + f(coins, i-1,x)*(1-coins[i]);
}
int main()
{
    int  n ;
    cin>>n;
    vector<double> coins (n,0);
    for(int i =0;i<n; i++) cin>>coins[i];
    cout<< fixed<<setprecision(10)<< f(coins, n-1, (n+1)/2);
}