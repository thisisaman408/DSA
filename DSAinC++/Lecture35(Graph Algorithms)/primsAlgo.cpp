/*
Another algo for finding the minimum spanning tree, first check the kruskal algo
to understand what is a minimum spanning tree
in a graph(undirected weighted graph)

this is also a greedy algo
bfs + greedy

here we use priority queue, as we used to use dsu in kruskal





The algo is following

Data structure used, unordered_map(), priority_queue<pair<wt,node>,
*/

// first we have to create a graph

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
using namespace std;
#define pp pair<int, int>
#define ll long long int
vector < list<pp> >graph;

void add_edge(int a, int b, int wt, bool bi_dir = true)
{
  graph[a].push_back({b, wt});
  if (bi_dir)
    graph[b].push_back({a, wt});
}

ll prims(int src, int n)
{
  priority_queue<pp, vector<pp>, greater<pp>> pq; // {wt, node}
  unordered_map<int, int> mp;                    // for mapping , to check if the new edge weight is lesser than the prev one, if it is then it's better edge than before!
  unordered_set<int> visited;                    // better to mark every node visited after we pop it out from queue, this will ensure, to not pop out the same element again, also it will help to avoid the prev {wt,node} in queue,
  vector<int> parent(n + 1);
  for (int i = 1; i <= n; i++)
  {
    mp[i] = INT_MAX;
    // initially every node from the src is at infinity distance
  }
  mp[src] = 0; // weight of src is 0,
  /*
  remember,
  in priority_queue there is {wt,node} pair
  in map there is {node,wt}

  cause in queue we want to sort on the basis of wt,
  and in the map we want node as the key and wt as the value

  wt is similar to distance

  */
  // push the src with 0 distance
  pq.push({0, src});   //{wt,node}
  int total_count = 0; // no of edges ,ofc it will go to n-1
  int result = 0;         // sum of wts

  // let's do a while loop
  while (total_count < n and !pq.empty())
  {
    pp curr = pq.top();
    //{wt,node}
    if (visited.count(curr.second))
    {
      // we are checknig if the "node" is visited
      pq.pop();
      // then just pop we do not need it
      continue;
    }

    // if it is not visited, then visit it
    visited.insert(curr.second);
    total_count++;        // we have visited another edge
    result += curr.first; // as it was {wt,node} so we will add the weight of this edge
    pq.pop();
    // i have completed my work for this current node,
    // now go to it's neighbout and repeat
    for (auto neighbour : graph[curr.second])
    { // curr ka second, node hai
      // neighbour is iterating on the list on graph at index i (say) and the list is having pair, {node, wt};
      // so when I say,  neighbour.first it reprepsents node, and when I say neighbour.second it represents wt
      /*
      If the neighbor has not been visited yet, and if the current weight to reach this neighbor (neighbour.second)
      is smaller than the weight already stored in the map (mp[neighbour.first]), then update the map.

      Explanation:
      - The map `mp` stores the minimum weight to reach each node.
      - The adjacency list contains neighbors as pairs (node, weight).
      - We are iterating through each neighbor, where `neighbour.first` is the node and `neighbour.second` is the weight.

      In simple terms:
      - We are comparing the weight of the current path to reach this neighbor (`neighbour.second`) with the weight
        already known and stored in the map (`mp[neighbour.first]`).
      - If the current path is cheaper, update the map.

      This ensures that if a cheaper path is found in the future, the map always holds the smallest known weight for each node.
  */
      if (!visited.count(neighbour.first) && mp[neighbour.first] > neighbour.second)
      {
        // Update the map with the smaller weight
        mp[neighbour.first] = neighbour.second;
        parent[neighbour.first] = curr.second;
        pq.push({neighbour.second, neighbour.first}); //{wt, node}
      }
    }
  }
  return result;
}
int main()
{
  int n, m;
  cin >> n >> m;
  graph.resize(n + 1, list<pp>());
  while (m--)
  {
    int src, dest, wt;
    cin >> src >> dest >> wt;
    add_edge(src, dest, wt);
  }
  int src;
  cin >> src;
  cout << prims(src,n) << endl;
}
