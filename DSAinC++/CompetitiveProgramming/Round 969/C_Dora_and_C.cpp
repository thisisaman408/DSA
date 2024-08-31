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
//solced by thisisaman408
#define ll long long
#define lli long long int

int custom_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve() {
    int n, a, b; 
    cin >> n >> a >> b;
    int c = custom_gcd(a, b);

    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        w[i] = (w[i] % c);
    }

    sort(w.begin() + 1, w.end());
    int ans = w[n] - w[1];

    for (int i = 1; i < n; i++) {
        ans = min(ans, w[i] + c - w[i + 1]);
    }

    cout << ans << endl;
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