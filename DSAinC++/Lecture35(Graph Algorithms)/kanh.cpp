// kanh's algo for topological sorting

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;
vector<list<int>> graph;
int v, e;

void add_edge(int a, int b, bool bi_dir = true)
{
    graph[a].push_back(b);
    if (bi_dir)
        graph[b].push_back(a);
}

void display()
{
    for (int i = 0; i < v; i++)
    {
        cout << i << "-> ";
        for (auto x : graph[i])
        {
            cout << x << " , ";
        }
        cout << endl;
    }
}

queue<int> q;
vector<int> indegree;
vector<int> topoSort;
unordered_set<int> visited;
void indegreeCalc()
{
    for (int i = 0; i < v; i++)
    {
        for (auto x : graph[i])
            indegree[x]++;
    }
}

void topoBFS()
{
    // kahn algo
    for (int i = 0; i < indegree.size(); i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int x = q.front();
        visited.insert(x);
        cout << x << " ";

        q.pop();
        topoSort.push_back(x);

        for (auto p : graph[x])
        {
            if (!visited.count(p))
            {
                indegree[p]--;
                if (indegree[p] == 0)
                {
                    q.push(p);
                    visited.insert(p);
                }
            }
        }
    }
    cout << endl;
    if (visited.size() != v)
        cout << "This not a DAG";
    else
        cout << "This is a DAG";
}

void printIndegree()
{
    for (int i = 0; i < indegree.size(); i++)
    {
        cout << indegree[i] << " ";
    }
    cout << endl;
}

int main()
{
    cin >> v;
    cin >> e;
    graph.resize(v, list<int>());
    indegree.resize(v, 0);
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        add_edge(x, y, false);
    }
    display();
    indegreeCalc();
    printIndegree();

    topoBFS();
}

/*

8
11
0 2
1 2
1 3
2 3
2 5
2 6
2 4
3 5
6 7
4 6
5 6




important, we don't really need to make a visited set here
cause

Why Revisiting Doesn’t Happen:
Indegree Counts: The algorithm processes nodes based on their indegree values.
Nodes are only added to the queue when their indegree becomes zero. Once a node
is processed (popped from the queue), it never gets added back because its indegree
cannot increase again.

Queue Management: The queue only contains nodes that are ready to be processed
(indegree == 0). Once processed, these nodes are removed from the queue and won’t
be revisited.

Indegree Decrementing: The indegree of a node is decremented only when one of
its predecessors is processed. When a node’s indegree reaches zero, it means all its predecessors have been processed, so it’s safe to add it to the queue.

Conclusion:
In Kahn’s algorithm, revisiting a node is not possible because once a node is
processed, its indegree doesn’t go back up, ensuring that it is never reconsidered
for processing. Therefore, you don’t need a visited set in this algorithm.
The indegree array is sufficient to handle everything.


*/