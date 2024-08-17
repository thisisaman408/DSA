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
    int lzero = 0;
    int lone = 0;
    int rzero = 0;
    int rone = 0;
    while(n--){
        int l,r;
        cin>>l>>r;
        if(l == 0) lzero++;
        else if(l == 1) lone++;
        if(r == 0) rzero++;
        else if(r == 1) rone++;
    }
    if(lzero < lone) ans += lzero;
    else ans += lone;
    if(rzero<rone) ans += rzero;
    else ans += rone;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}