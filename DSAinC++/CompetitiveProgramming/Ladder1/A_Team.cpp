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
   int n;
   cin>>n;
   int ans = 0;
   while(n--){
    int a,b,c;
    cin>>a>>b>>c;
    if((a == 1 and b == 1 )or (a == 1 and c == 1) or( b==1 and c== 1)){
       ans++;
    }
   }
   cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}