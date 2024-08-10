/*
Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

Input
There will be a number of test cases in the input.

The first line of each test case will contain n, the number of mixtures, 1 <= n <= 100.

The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

Output
For each test case, output the minimum amount of smoke.

*/

#include <iostream>
#include <vector>
#include <climits>
#include<cstring>
using namespace std;

int g(int i, int j, vector<int>&col){
    int res = 0;
    for(int u = i;u<=j;u++) res = (res%100 + col[u]%100)%100;
    return res;
}
int dp[105][105];
int f(int i, int j, vector<int>& col){
    if(i == j) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    int smoke = INT_MAX;
    for(int k=i;k<j;k++) smoke = min(smoke,f(i,k,col)+f(k+1,j,col)+g(i,k,col)*g(k+1,j,col));
    return dp[i][j] = smoke;
}

int bup(vector<int>&col){
  int n =col.size();
  memset(dp,-1,sizeof(dp));
  for (int i = 0; i < n; ++i)dp[i][i] = 0;
  for(int len = 2; len <=n; len++){
    for(int i = 0; i<= n - len;i++){
        int j = i+len -1;
        int smoke = INT_MAX;
        for(int k=i;k<j;k++) smoke = min(smoke, dp[i][k] + dp[k+1][j] + g(i,k,col)*g(k+1,j,col));
        dp[i][j] = smoke;
    }
  }
  return dp[0][n-1];
}
int main()
{
    int n;
    while(cin>>n){
        memset(dp,-1,sizeof(dp));
        vector<int> col(n,0);
        for(int i=0;i<n;i++) cin>> col[i];
        cout<<bup(col)<<endl;
    }
    return 0;
}