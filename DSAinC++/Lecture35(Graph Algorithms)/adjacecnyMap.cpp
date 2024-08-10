#include<iostream>
#include<list>
#include<vector>

using namespace std;


vector<list <pair<int,int> >> graph;
int v;

void add_edge(int s, int d,int wt,  bool bi_dir = true){
    graph[s].push_back({d,wt});
    if(bi_dir) graph[d].push_back({s,wt});
}

void display(vector<list<pair<int,int>>> &graph){
    for(int i = 0; i < graph.size(); i++){
        cout<<i<<"->";
        for(auto ele : graph[i]){
            cout<<"("<<ele.first << " "<<ele.second<<")";
        }
        cout<<endl;
    }
}
int main(){
    cin>>v;
    graph.resize(v,list<pair<int,int>>());
    int e;
    cin>>e;
    while(e--){
        int s, d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }
   display(graph);
}

/*

7 
7
0 2 2
0 1 1
1 5 3
2 5 2
2 3 6
3 6 2
6 4 4

*/