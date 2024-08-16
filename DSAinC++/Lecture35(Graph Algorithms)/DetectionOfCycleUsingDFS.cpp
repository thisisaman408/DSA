#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include<cstring>
#include<string.h>
#include<list>
#include<unordered_set>

using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int

vector<list<int>> graph;
int v;

void add_edge(int x, int y, bool bi_dir = true){
    graph[x].push_back(y);
    if(bi_dir) graph[y].push_back(x);
}


// in this algo it is simple if you get an element which is visited but not your parent, then 
//there's a cycle there in the graph

void display(){
    for(int i =0; i < v;i++){
        cout<<i<<"-> ";
        for(auto x : graph[i]) cout<<x<<" , ";
        cout<<endl;
    }
}

//Tc : O(V+E)
bool dfs(int src, int parent, unordered_set<int> &visited)
{
    visited.insert(src);
    for(auto x : graph[src]){
        if(visited.count(x) and x != parent) return true; //cycle has detected
        if(!visited.count(x)) 
        {
            if(dfs(x,src,visited)) return true;
        }
    }
    return false;
}
bool hasCycle(){
    unordered_set<int> visited;
    bool ans = false;
    for(int i = 0; i < v;i++){
        if(!visited.count(i)) {
            if (dfs(i, -1, visited)) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int>());
    while(e--){
        int x,y;
        cin>>x>>y;
        add_edge(x,y);
    }
    
    display();
    cout<<hasCycle();
    return 0;
}