#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include<cstring>
#include<string.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int

const int MAX_N = 2000;
const int MAX_H = 2000;

int n, h, l, r;
int a[MAX_N];
int dp[MAX_N][MAX_H];

int maxGoodTime(int i, int c_t){
    if(i == n) return 0;
    if(dp[i][c_t] != -1) return dp[i][c_t];
    int time1 = (c_t + a[i])%h;
    int time2 = (c_t + a[i] - 1) %h;
    int good1 = (l<= time1 and time1 <= r)? 1:0;
    int good2 = (l<= time2 and time2 <= r) ? 1: 0;

    int option1 = good1 + maxGoodTime(i+1,time1);
    int option2 = good2 + maxGoodTime(i+1,time2);

    return dp[i][c_t] = max(option1,option2);
}

void solve() {
    memset(dp,-1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = maxGoodTime(0,0);
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   cin>>n>>h>>l>>r;
   solve();


    return 0;
}