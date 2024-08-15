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
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    r++;
    R++;
    
    if (r <= L || R <= l)  cout << 1 << "\n";
    else {
        if (l > L) swap(l, L);
        if (r > R)  swap(r, R);
        cout << min(r, R - 1) - max(l + 1, L) + 1 << "\n";
    }
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