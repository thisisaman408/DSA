#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 300005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        vector<vector<int>> dpA(n, vector<int>(n, 0));
        vector<vector<int>> dpB(n, vector<int>(n, 0));

        // Base cases
        for (int i = 0; i < n; ++i) {
            dpA[i][i] = a[i];
            dpB[i][i] = b[i];
        }

        // Fill DP tables
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dpA[i][j] = max(a[i] - dpB[i + 1][j], a[j] - dpB[i][j - 1]);
                dpB[i][j] = max(b[i] - dpA[i + 1][j], b[j] - dpA[i][j - 1]);
            }
        }

        // Determine the winner
        if (dpA[0][n - 1] > 0) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }

    return 0;
}
