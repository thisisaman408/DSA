#include<iostream>
#include<vector>
using namespace std;

//this solution is wrong right now!

const int MAXN = 2e5 + 10;
vector<int> tree[MAXN];
int depth[MAXN];
int weight[MAXN];
int n, q;

void dfs(int u, int par, int d) {
    depth[u] = d;
    for (int v : tree[u]) {
        if (v != par) {
            dfs(v, u, d + 1);
        }
    }
}

void calculate_max_distance_sum() {
    long long max_distance_sum = 0;
    for (int i = 1; i <= n; i++) {
        int j = (i % n) + i;
        int distance = abs(depth[i] - depth[j]);
        max_distance_sum += distance;
    }
    cout << max_distance_sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> parent(n + 1,1);
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

        for (auto& query : queries)  calculate_max_distance_sum();
    }

    return 0;
}
