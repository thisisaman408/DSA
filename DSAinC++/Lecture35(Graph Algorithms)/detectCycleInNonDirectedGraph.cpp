/*


How to determine if there is a cycle in non directed graph???

There are 3 methods...!!!!

1) BFS
2) DFS
3) DSU


we will do by all of these here



*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int find(unordered_map<int, int> &parent, int val)
{
    if (parent[val] != val) parent[val] = find(parent, parent[val]);
    // Path compression
    return parent[val];
    // this is path compressing, storing the values in the parent[val] in returning
}

bool Union(unordered_map<int, int> &parent, unordered_map<int, int> &rank, int a, int b)
{
    int rootA = find(parent, a);
    int rootB = find(parent, b);
    if (rootA == rootB) return true;
    // if both have same parent thus there exist a cycle

    if (rootA != rootB)
    {
        if (rank[rootA] < rank[rootB]) parent[rootA] = rootB;
        else if (rank[rootA] > rank[rootB])  parent[rootB] = rootA;
        else
        {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    // Initialize parent and rank for the first n elements
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    bool x = true;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (parent.find(a) == parent.end())
        {
            parent[a] = a;
            rank[a] = 0;
        }
        if (parent.find(b) == parent.end())
        {
            parent[b] = b;
            rank[b] = 0;
        }
        x = Union(parent, rank, a, b);
       if(x) {cout<<"Cycle detected"; x = false;}
    }
    if(x) cout<<"No cycle found";

}