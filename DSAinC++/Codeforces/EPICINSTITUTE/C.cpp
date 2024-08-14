#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> startIndex, endIndex;
vector<int> dfsOrder;
int indexCounter = 0;

// Perform DFS to compute entry and exit times and store DFS order
void dfs(int node) {
    startIndex[node] = indexCounter++;
    dfsOrder.push_back(node);
    for (int child : tree[node]) {
        dfs(child);
    }
    endIndex[node] = indexCounter;
}

// Function to check if a permutation is a valid DFS order
bool isValidDFSOrder(const vector<int>& perm) {
    unordered_map<int, int> pos;
    for (int i = 0; i < perm.size(); ++i) {
        pos[perm[i]] = i;
    }

    for (int i = 0; i < perm.size(); ++i) {
        int node = perm[i];
        for (int child : tree[node]) {
            if (pos[child] < pos[node] || pos[child] >= endIndex[node]) {
                return false;
            }
        }
    }
    return true;
}

void solveTestCase(int n, int q, vector<int>& parents, vector<int>& perm, vector<pair<int, int>>& queries) {
    tree.assign(n + 1, vector<int>());
    for (int i = 2; i <= n; ++i) {
        tree[parents[i - 2]].push_back(i);
    }

    startIndex.assign(n + 1, 0);
    endIndex.assign(n + 1, 0);
    dfsOrder.clear();
    indexCounter = 0;
    dfs(1);

    unordered_map<int, int> dfsOrderIndex;
    for (int i = 0; i < n; ++i) {
        dfsOrderIndex[dfsOrder[i]] = i;
    }

    for (const auto& query : queries) {
        int x = query.first - 1;
        int y = query.second - 1;
        swap(perm[x], perm[y]);

        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (dfsOrderIndex[perm[i]] != i) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> parents(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> parents[i];
        }
        
        vector<int> perm(n);
        for (int i = 0; i < n; ++i) {
            cin >> perm[i];
        }
        
        vector<pair<int, int>> queries(q);
        for (int i = 0; i < q; ++i) {
            int x, y;
            cin >> x >> y;
            queries[i] = {x, y};
        }
        
        solveTestCase(n, q, parents, perm, queries);
    }

    return 0;
}
