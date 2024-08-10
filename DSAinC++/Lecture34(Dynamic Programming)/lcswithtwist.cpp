/*
Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem. Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash. To complicate matters, a twist was introduced in the problem.

In addition to the two sequences, an additional parameter k was introduced. A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change at most k elements in the first sequence to any value you wish to. Can you help Mancunian solve this version of the classical problem?

Input:
The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the value of the provided parameter respectively.
The second line contains N integers denoting the elements of the first sequence.
The third line contains M integers denoting the elements of the second sequence.



https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/?utm_source=header&utm_medium=search&utm_campaign=he-search
*/

#include <iostream>
#include <vector>
#include<cstring>
#define ll long long
using namespace std;
ll dp[1000][1000][8];
ll f(vector<int>&a, vector<int>&b, int i, int j, int k){

    if(i == a.size() || j == b.size()) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    ll res = 0;
    if(a[i] == b[j]) res = 1 + f(a,b,i+1,j+1,k);
    else{
        if(k > 0) res = 1 + f(a,b,i+1,j+1,k-1);
        res = max(res,f(a,b,i+1,j,k));
        res = max(res,f(a,b,i,j+1,k));
    }
    return dp[i][j][k] = res;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    vector<int> first (n);
    vector<int>second(m);

    for(int i = 0; i <n;i++) cin>>first[i];
    for(int i = 0; i <m;i++) cin>>second[i];

    cout<<f(first,second,0,0,k);

}