#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include<queue>
#include<climits>
using namespace std;

#define pp pair<int, int>
#define ll long long int
vector<list<pp>> graph;
void add_edge(int a, int b, int wt, bool bi_dir = true)
{
  graph[a].push_back({b, wt});
  if (bi_dir) graph[b].push_back({a, wt});
}
ll prims(int src,int n){
  unordered_map<int,int>mp; //{node,wt}
  priority_queue<pp, vector<pp> ,greater<pp>> pq; //{wt,node}
  unordered_set<int> visited;
  vector<int>parent(n+1);

  for(int i = 1; i<=n; i++) mp[i] = INT_MAX;
  mp[src]= 0;
  pq.push({0,src});

  int edge_Count = 0; // 0 -> n-1
  ll ans = 0;
  while(edge_Count < n and !pq.empty()){
    pp x = pq.top();
    if(visited.count(x.second)){
      pq.pop();
      continue;
    }

    visited.insert(x.second);
    ans += x.first;
    edge_Count++;
    pq.pop();
    for(auto neighbour : graph[x.second]){
      if(!visited.count(neighbour.first) and mp[neighbour.first] > neighbour.second){
        mp[neighbour.first] = neighbour.second;
        pq.push({neighbour.second, neighbour.first});
        parent[neighbour.first] = x.second;
      }
    }
  }
  return ans;
}
int main()
{
  int n, m;
  cin >> n >> m;
  // n -> no of vertices, m -> no of edges
  graph.resize(n+1, list<pp>());
  while (m--)
  {
    int src, dest, wt;
    cin >> src >> dest >> wt;
    add_edge(src, dest, wt);
  }

  int source;
  cin>>source;
  cout<<prims(source, n);
}