#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 500;
const long long MOD = 1000000007;

vector<vector<long long> > dp(MAX_N + 1, vector<long long>(MAX_N + 1, 0));
vector<vector<long long> > comb(MAX_N + 1, vector<long long>(MAX_N + 1, 0));
vector<long long> fact(MAX_N + 1, 1);
vector<long long> inv_fact(MAX_N + 1, 1);

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void precompute_combinations(int max_n, long long mod) {
    for (int i = 2; i <= max_n; ++i) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv_fact[max_n] = mod_pow(fact[max_n], mod - 2, mod);
    for (int i = max_n - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
    for (int i = 0; i <= max_n; ++i) {
        for (int j = 0; j <= i; ++j) {
            comb[i][j] = fact[i] * inv_fact[j] % mod * inv_fact[i - j] % mod;
        }
    }
}

long long count_deterministic_max_heaps(int n, int k, long long p) {
    vector<vector<long long> > dp(n + 1, vector<long long>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        int total_nodes = (1 << i) - 1;
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 0;
            for (int l = 0; l <= j; ++l) {
                int left_nodes = (1 << (i - 1)) - 1;
                int right_nodes = left_nodes;
                long long ways = comb[left_nodes + right_nodes][left_nodes];
                dp[i][j] = (dp[i][j] + dp[i - 1][l] * ways % p) % p;
            }
        }
    }

    return dp[n][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;
        precompute_combinations(MAX_N, p);
        cout << count_deterministic_max_heaps(n, k, p) << endl;
    }

    return 0;
}
