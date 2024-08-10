//for unweighted graph, hence using bfs

#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_set>

using namespace std;


vector<list<int>> graph;
int v;

unordered_set<int> visited;
vector<int> b;

void bfs(int s,vector<int>& dist){
    queue<int> q;
    visited.clear();
    dist.resize(v, INT_MAX);
    dist[s] = 0;
    visited.insert(s);
    q.push(s);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto ele: graph[curr]){
            if(!visited.count(ele)){
                q.push(ele);
                visited.insert(ele);
                dist[ele] = dist[curr] + 1;
            }
        }
        
    }
}


void add_edge(int s, int d, bool bi_dir = true){
    graph[s].push_back(d);
    if(bi_dir) graph[d].push_back(s);
}

void display(){
    for(int i =0; i< graph.size(); i++){
        cout<<i<<"->";
        for(auto ele : graph[i]){
            cout<<ele<<" , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    cout<<endl;
    int x;
    cin>>x;
    display();
    cout<<endl;
    vector<int> v;
    bfs(x,v);
    for(int i = 0; i < v.size();i++){
        cout<<v[i]<<" ";
    }
}

/*



7
8
0 1
0 4
1 3
4 3
1 5
5 6
6 2
5 2


*/