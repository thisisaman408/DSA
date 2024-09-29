#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// Solved by Aman -> thisisaman408

#define ll long long
#define lli long long int

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    int x_moves, y_moves;
    if (x % k == 0) {
        x_moves = x / k;
    } else {
        x_moves = (x / k) + 1;
    }
    if (y % k == 0) {
        y_moves = y / k;
    } else {
        y_moves = (y / k) + 1;
    }
    int min_moves = min(x_moves, y_moves);
    int max_moves = max(x_moves, y_moves);
    int total_moves = min_moves + max_moves + (max_moves - min_moves);
    if (x_moves > y_moves) {
        total_moves--;
    }

    cout << total_moves << endl;
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
