#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>

using namespace std;

vector<list<int>> graph;
int v;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) graph[dest].push_back(src);
}

void display(const vector<list<int>> &graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto ele : graph[i]) cout << ele << " , ";
        cout << endl;
    }
}

bool bfs(int start, unordered_set<int> &visited) {
    vector<int> parent(v, -1);
    queue<int> q;
    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr]) {
            // If the neighbor is visited and is not the parent of the current node, cycle detected
            if (visited.count(neighbor) && parent[curr] != neighbor) return true;
            // If the neighbor hasn't been visited, process it
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                parent[neighbor] = curr; // Set the parent of this neighbor
                q.push(neighbor);
            }
        }
    }

    return false;
}

bool hasCycle() {
    unordered_set<int> visited;
    for (int i = 0; i < v; i++) {
        if (!visited.count(i)) if(bfs(i,visited)) return true;
    }
    return false;
}

int main() {
    cin >> v;
    graph.resize(v);

    int e;
    cin >> e;

    while (e--) {
        int src, dest;
        cin >> src >> dest;
        add_edge(src, dest);//undirected graph
    }

    display(graph);

    if (hasCycle()) cout << "Cycle detected" << endl; 
    else  cout << "No cycle detected" << endl;
    return 0;
}
