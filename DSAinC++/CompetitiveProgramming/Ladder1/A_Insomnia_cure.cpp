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

void solve() {
   int k,l,m,n,d;
   int count=0;
   cin>>k>>l>>m>>n>>d;
   for(int i = 1; i<= d;i++) if(i%m == 0 or i%l ==0 or i%k ==0 or i%n == 0) count++;
   cout<<count<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}