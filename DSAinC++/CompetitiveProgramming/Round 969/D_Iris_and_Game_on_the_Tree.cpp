#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cstring>
#include <string.h>

using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int
//solved by thisisaman408
const int N = 1e5 + 10;
int w[N];
vector<int> g[N];
bool vis[N];
int cnt = 0;
int f[N];

void dfs(int u) {
    int c = 0;
    vis[u] = true;
    for (int v : g[u]) {
        if (vis[v]) continue;
        ++c;
        dfs(v);
    }
    if (!c) ++f[w[u]];
    else if (u != 1 && w[u] == 2) ++cnt;
}

void solve() {
    int n;
    cin >> n;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = false;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') w[i + 1] = 2;
        else w[i + 1] = s[i] - '0';
    }
    f[0] = f[1] = f[2] = 0;
    dfs(1);
    int ans = 0;
    if (w[1] == 0) ans = f[1] + (f[2] + 1) / 2;
    if (w[1] == 1) ans = f[0] + (f[2] + 1) / 2;
    if (w[1] == 2 && f[0] == f[1]) ans = f[1] + (f[2] + (cnt % 2)) / 2;
    if (w[1] == 2 && f[0] != f[1]) ans = max(f[0], f[1]) + f[2] / 2;
    cout << ans << '\n';
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
