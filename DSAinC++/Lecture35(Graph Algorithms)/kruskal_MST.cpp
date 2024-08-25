
// in an undirected connected and weighted graph, we have to find an special subtree,
/*

which has,
tree means no cycle,

the subtree is a subgraph of our given graph

this subgraph must contains all the vertices of the graph
(all edges might not be taken )



There must be only one exclusive path from one node to every other node.


There can be many subgraphs like this of a particular graph
in our this special subtree of subgraph,
the subgraph is of minimum weight among all such subgraphs






THIS SPECIAL TREE IS CALLED MINIMUM SPANNING TREE (MST)


- Tree, thus no cycles
- includes all the nodes of the graph
- sum of the edges weight is minimum

we can find a MST, using kruskal and prim's algo

both are GREEDY algo !!!!!!!



if you see the name
which is minimum spanning tree
tree means a subgraph

spanning means

minimum edges required to just connect the graph
*/

/*
Kruskal's


One by One keep a picky edge with minimum weight
if picking a particular edge creates a cycle, AVOID IT, else choose it



I am given a edge list,
Here,
I am gonna sort the edge list first
now we have to detect a cycle, and edge list is given,it's really easy if we use DSU
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int

struct Edge {
    int src, dest, wt;
};

// Function to find the root/representative of a set with path compression
int find(vector<int>& parent, int val) {
    if (parent[val] != val) {
        parent[val] = find(parent, parent[val]);
    }
    return parent[val];
}

// Function to perform union of two sets by rank
void Union(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a != b) {
        if (rank[a] < rank[b]) {
            parent[a] = b;
        } else if (rank[a] > rank[b]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }
}

// Comparator function for sorting edges by weight in ascending order
bool cmp(Edge a, Edge b) {
    return a.wt < b.wt;
}

// Function implementing Kruskal's algorithm
ll kruskal(vector<Edge>& edges, int n, int e) {
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    // Initializing each node to be its own parent
    for (int i = 0; i <= n; i++) parent[i] = i;

    ll sum = 0;
    int edgeCount = 0; // to keep track of the number of edges in the MST

    for (int i = 0; i < e; i++) {
        if (edgeCount == n - 1) break; // Stop when we have n-1 edges in the MST

        Edge curr = edges[i];
        int srcPar = find(parent, curr.src);
        int destPar = find(parent, curr.dest);

        if (srcPar != destPar) {
            Union(parent, rank, srcPar, destPar);
            sum += curr.wt;
            edgeCount++;
        }
    }

    return sum;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edges(e);

    for (int i = 0; i < e; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].wt;
    }

    cout << kruskal(edges, n, e) << endl;

    return 0;
}
