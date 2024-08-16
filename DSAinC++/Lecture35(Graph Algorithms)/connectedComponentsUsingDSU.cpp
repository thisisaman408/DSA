#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

// Function to find the representative (root) of a component using path compression
int find(unordered_map<int, int>& parent, int val) {
    if (parent[val] != val) {
        parent[val] = find(parent, parent[val]); // Path compression
    }
    return parent[val];
}

// Function to perform union by rank
void Union(unordered_map<int, int>& parent, unordered_map<int, int>& rank, int a, int b) {
    int rootA = find(parent, a);
    int rootB = find(parent, b);

    if (rootA != rootB) {
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and number of edges: ";
    cin >> n >> m;

    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    // Initialize parent and rank for each node
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    vector<pair<int, int>> edges;

    cout << "Enter edges (pairs of nodes):" << endl;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});

        if (parent.find(a) == parent.end()) {
            parent[a] = a;
            rank[a] = 0;
        }
        if (parent.find(b) == parent.end()) {
            parent[b] = b;
            rank[b] = 0;
        }
        Union(parent, rank, a, b);
    }

    // Group nodes by their root
    unordered_map<int, vector<int>> connectedComponents;
    for (int i = 0; i < n; ++i) {
        int root = find(parent, i);
        connectedComponents[root].push_back(i);
    }

    // Print sizes of each connected component and the components themselves
    cout << "\nConnected components and their sizes:" << endl;
    for (const auto& component : connectedComponents) {
        cout << "Root: " << component.first << ", Size: " << component.second.size() << endl;
        cout << "Nodes: ";
        for (int node : component.second) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
