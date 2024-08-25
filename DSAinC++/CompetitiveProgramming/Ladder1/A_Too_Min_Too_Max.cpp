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
    vector<int> v(n);
   bool flag = true;
    int x = INT_MIN;
    int j,k;
    for(int i=0;i<n;i++) {
        cin>>v[i];
       if(v[i] != v[i-1]){
        j= i;
        flag = false;
       }
       if(flag && v[i] != v[i-1]){
        k= i;
       }
    }
    int i=0;
    int l = 1;
    for(int i =0; i< n;i++){
        for(int j = (i+1)%n; j < n; j++){
            x = max(x,abs(v[i]) - abs(v[j]));
        }
    }
    cout<<x<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin>>t;  
    while(t--) {
        solve();
    }

    return 0;
}