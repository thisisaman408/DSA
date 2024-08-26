/*


You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.



*/

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

#define ll long long int
struct Edge{
        int src;
        int dest;
        int wt;
    };
bool cmp(Edge a, Edge b){
    return a.wt < b.wt;
}
class Solution {
public:
    int dist(vector<int>&a, vector<int>&b){
        return abs(b[0] - a[0]) + abs(b[1] - a[1]);//manhattan distance
    }
    int find(vector<int>&parent, int val){
        if(parent[val] != val) parent[val] = find(parent, parent[val]);
        return parent[val];
    }
    void Union(vector<int>&parent, vector<int>&rank, int a, int b){
        a = find(parent,a);
        b = find(parent,b);
        if(a == b) return;//we do not want cycle
        if(a != b){
            if(rank[a] < rank[b]) parent[a] = b;
            else if (rank[a] > rank[b]) parent[b]= a;
            else {
                parent[b] = a;
                rank[a]++;
            }
        }
    }
    ll kruskal(vector<Edge>edges,int n){
        sort(edges.begin(), edges.end(),cmp);
        ll ans =0;
        vector<int>parent(n+1);
        for(int i = 0; i<n; i++) parent[i] = i;
        vector<int>rank(n+1,0);
        int i =0;
        int edgeCount = 0;
        while(edgeCount < n-1 and i < edges.size()){
            Edge curr = edges[i];
            int srcPar = find(parent,curr.src);
            int destPar = find(parent, curr.dest);
            if(srcPar != destPar){
                Union(parent,rank,srcPar, destPar);
                ans += curr.wt;
                edgeCount++;
            }
            i++;
        }
    return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
       vector<Edge> graph;
        //we have to create a complete graph
        int n= points.size();
        int j = 0;
       for(int i = 0; i< n;i++){
            for(int j = i+1; j < n;j++){
                int d = dist(points[i], points[j]);
                graph.push_back({i, j, d});
            }
       }
       return kruskal(graph,n);
    }
};

int main(){
  vector<vector<int>>points = {{0,0}, {2,2},{3,10}, {5,2},{7,0}};
  Solution sol;
  cout<<sol.minCostConnectPoints(points)<<endl;
}