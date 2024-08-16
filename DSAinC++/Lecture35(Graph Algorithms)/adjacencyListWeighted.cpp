#include<iostream>
#include<vector>
#include<list>

using namespace std;


vector<list<pair<int,int>>> graph;
int v; // no of vertices

void add_edge(int src, int dest,int wt, bool bi_dir = true){
    graph[src].push_back({dest,wt});
    if(bi_dir)  graph[dest].push_back({src, wt});     
}

void display(vector<list<pair<int,int>>>& graph){
    for(int i = 0; i< graph.size(); i++){
        cout<<i<< "-> ";
        for(auto ele : graph[i]){
            cout<<"("<<ele.first<<","<<ele.second<<")"<<" , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    graph.resize(v, list<pair<int,int>>());
    int e;
    cin>>e;
    int w;
    cin>>w;
    while(e--){
        int src, dest,wt;
        cin>>src>>dest>>wt;
        add_edge(src,dest,wt,false);
    }
    display(graph);
}