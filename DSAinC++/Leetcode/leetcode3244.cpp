#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> shortestPath(int n, vector<vector<int>>& queries) {
    vector<vector<pair<int, int>>> adjList(n);
    vector<int> answer;
    for (int i = 0; i < n - 1; ++i) {
        adjList[i].emplace_back(i + 1, 1);
    }
    auto dijkstra = [&]() -> int {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[0] = 0;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) break;

            for (auto [v, w] : adjList[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist[n - 1];
    };

    for (auto& q : queries) {
        int u = q[0];
        int v = q[1];
        adjList[u].emplace_back(v, 1);
        answer.push_back(dijkstra());
    }

    return answer;
}