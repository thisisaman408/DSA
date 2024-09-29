#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 200001;
int fa[MAXN], dep[MAXN];
int c1[MAXN], c2[MAXN], len[MAXN];

//solved by Aman -> thisisaman408

#define ll long long
#define lli long long int

void solve() {
    int N;
    ll w;
    cin >> N >> w;

    for (int i = 2; i <= N; ++i) cin >> fa[i]; 
    for (int i = 2; i <= N; ++i) dep[i] = dep[fa[i]] + 1; 

    for (int i = 1; i <= N; ++i) len[i] = c1[i] = 0;
    for (int i = 1; i <= N; ++i) {
        int x = i, y = (i == N ? 1 : i + 1);
        while (x != y) {
            if (dep[x] < dep[y]) swap(x, y);  
            (c1[x] ? c2[x] : c1[x]) = i;  
            x = fa[x];
            ++len[i]; 
        }
    }

    ll sum = 0, sur = N;
    for (int i = 1; i < N; ++i) {
        int x;
        ll cost;
        cin >> x >> cost;
        sum += cost;

        if ((--len[c1[x]]) == 0) --sur; 
        if ((--len[c2[x]]) == 0) --sur;
        cout << sum * 2 + sur * (w - sum) << (i == N - 1 ? '\n' : ' ');
    }
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
