#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cstring>
#include <string.h>
#include <cstdint>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// Solved by Aman -> thisisaman408

#define ll long long
#define lli long long int

void solve() {
    ll a, b;
    cin >> a >> b;
    ll sum1 = (b * (b - 1)) / 2;
    ll c = b + a - 1;
    ll sum2 = (c * (c + 1)) / 2;
    ll sum = sum2 - sum1;
    ll min_diff = INT64_MAX;
    ll s = 0;
    while (true) {
        s += c;      
        sum -= c;     
        c--;        
        ll diff = abs(sum - s);
        min_diff = min(min_diff, diff);
        if (diff > min_diff) {
            break;
        }
    }
    cout << min_diff << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
