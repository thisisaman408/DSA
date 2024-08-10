#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int> >graph;
int v; //no of vertices


void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}


void dfs(int node, unordered_set<int> &visited){
    visited.insert(node);
    for(auto neighbor : graph[node]){
        if(!visited.count(neighbor)){
            dfs(neighbor,visited);
        }
    }
}

int noOfConnectedComponents(){
    int count = 0;
    unordered_set<int> visited;
    for(int i = 0 ; i < v; i++){
       if(visited.count(i) == 0){
            count++;
            dfs(i,visited);
       }
    }
    return count;
}
void display(){

    for(int i = 0; i< graph.size(); i++){
        cout<<i<<"->";
        for(auto x : graph[i]){
            cout<<x<<" , ";
        }
        cout<<endl;
    }
}
int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;//no of edges
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();
    int count = 0;
    cout<<noOfConnectedComponents()<<endl;
}