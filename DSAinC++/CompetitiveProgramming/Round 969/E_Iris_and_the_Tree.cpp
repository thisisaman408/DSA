#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> tree[MAXN];
int depth[MAXN];
int weight[MAXN];
int n, q;

// DFS to calculate depth of each node
void dfs(int u, int par, int d) {
    depth[u] = d;
    for (int v : tree[u]) {
        if (v != par) {
            dfs(v, u, d + 1);
        }
    }
}

// Calculate the maximum possible distance sum after updates
void calculate_max_distance_sum() {
    long long max_distance_sum = 0;
    for (int i = 1; i <= n; i++) {
        int j = (i % n) + 1;
        // Adjust i and j for 1-based indexing
        int distance = abs(depth[i] - depth[j]);
        max_distance_sum += distance;
    }
    cout << max_distance_sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> parent(n + 1);
        for (int i = 2; i <= n; i++) {
            cin >> parent[i];
            tree[parent[i]].push_back(i);
            tree[i].push_back(parent[i]);
        }

        dfs(1, -1, 0);

        vector<pair<int, int>> queries(n - 1);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            queries[i] = {x, y};
        }

        for (auto& query : queries) {
            // Here we would handle updates if necessary
            // For now, we simply calculate max distance sum after all updates
            calculate_max_distance_sum();
        }
    }

    return 0;
}
