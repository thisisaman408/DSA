#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;
#define pp pair<double, int>

class Solution {
public:
    double maxProbability(int n, vector<vector<double>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // building a graph
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        priority_queue<pp> pq; // max heap
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (node == end_node) return prob;

            for (auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;

                if (maxProb[nextNode] < prob * edgeProb) {
                    maxProb[nextNode] = prob * edgeProb;
                    pq.push({maxProb[nextNode], nextNode});
                }
            }
        }

        return 0.0;
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<vector<double>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> successProb = {0.5, 0.5, 0.2};
    int start = 0;
    int end = 2;
    cout << sol.maxProbability(n, edges, successProb, start, end) << endl;
}
