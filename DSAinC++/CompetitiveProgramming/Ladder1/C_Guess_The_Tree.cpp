#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <tuple>
#include <functional>

using namespace std;

// Custom hash function for std::tuple<int, int, int>
struct TupleHash {
    template <typename T1, typename T2, typename T3>
    std::size_t operator()(const std::tuple<T1, T2, T3>& t) const {
        std::size_t h1 = std::hash<T1>{}(std::get<0>(t));
        std::size_t h2 = std::hash<T2>{}(std::get<1>(t));
        std::size_t h3 = std::hash<T3>{}(std::get<2>(t));
        return h1 ^ (h2 << 1) ^ (h3 << 1); // Combine the hash values
    }
};

unordered_set<tuple<int, int, int>, TupleHash> queryResults;

void query(int a, int b, int& result) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    cin >> result;
    // Insert the query and its result into the set
    queryResults.insert(make_tuple(a, b, result));
}

void output(vector<pair<int, int>>& edges) {
    cout << "! ";
    for (auto& edge : edges) cout << edge.first << " " << edge.second << " ";
    cout << endl;
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > adj(n + 1);
        vector<pair<int, int>> edges;
        vector<int> parent(n + 1, -1); 

        for (int i = 2; i <= n; ++i) {
            int lca;
            query(1, i, lca);
            if (lca == 1) {
                edges.emplace_back(1, i);
                adj[1].push_back(i);
                adj[i].push_back(1);
                parent[i] = 1;
            } else {
                
                edges.emplace_back(lca, i);
                adj[lca].push_back(i);
                adj[i].push_back(lca);
                parent[i] = lca;
            }
        }

        output(edges);
    }
    
    return 0;
}
