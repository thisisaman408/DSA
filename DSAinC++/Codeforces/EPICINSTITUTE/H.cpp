#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        // Initialize DP table
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n / 3 + 1, vector<int>(m + 1, 0)));
        
        // Base case: Sequences of length 1 with 0 operations
        for (int i = 1; i <= m; ++i) {
            dp[1][0][i] = 1;
        }
        
        // Fill the DP table
        for (int length = 1; length <= n; ++length) {
            for (int k = 0; k <= n / 3; ++k) {
                for (int max_val = 1; max_val <= m; ++max_val) {
                    if (dp[length][k][max_val] > 0) {
                        // Adding a new element
                        if (length + 1 <= n) {
                            for (int new_val = 1; new_val <= m; ++new_val) {
                                dp[length + 1][k][max(max_val, new_val)] = (dp[length + 1][k][max(max_val, new_val)] + dp[length][k][max_val]) % MOD;
                            }
                        }
                        // Performing an operation if possible
                        if (length >= 3 && k + 1 <= n / 3) {
                            for (int new_val = 1; new_val <= m; ++new_val) {
                                dp[length - 2][k + 1][max(max_val, new_val)] = (dp[length - 2][k + 1][max(max_val, new_val)] + dp[length][k][max_val]) % MOD;
                            }
                        }
                    }
                }
            }
        }
        
        // Output the result
        for (int k = 0; k <= n / 3; ++k) {
            int result = 0;
            for (int max_val = 1; max_val <= m; ++max_val) {
                result = (result + dp[n][k][max_val]) % MOD;
            }
            cout << result << " ";
        }
        cout << endl;
    }
    
    return 0;
}


/*

2
3 2
10 10


*/