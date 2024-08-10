#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>

using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
int v;


void add_edge(int s, int d, bool bi_dir = true){
    graph[s].push_back(d);
    if(bi_dir) graph[d].push_back(s);
}

//tc of dfs is O(V+E), V-> no of vertices, E-> no of edges
//sc O(V)
void dfs(int curr,int end, vector<int>&path){
    if(curr == end) {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);// mark it visited
    path.push_back(curr);
    for(auto neighbour : graph[curr]){
        if(!visited.count(neighbour)){// if the curr is not in visited, then we will check for it's neighbour
            dfs(neighbour,end,path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
    
}


void anyPath(int start, int end){
    visited.clear();
    vector<int> v;
    dfs(start,end,v);
}
void display(){
    for(int i = 0; i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<ele<<" , ";
        }
        cout<<endl;
    }
}

int main(){
    cin >> v; // Input number of vertices
    graph.resize(v, list<int>()); // Resize the graph

    int e; // Number of edges
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d;
        add_edge(s, d); // Add edge to the graph
    }

    int x, y; // Start and end vertices for path checking
    cout<<"Now enter the two vertices between which you want to find the paths"<<endl;
    cin >> x >> y;

    display(); // Display the graph
    cout << endl;
    anyPath(x,y);
    for(auto path : result){
        for(auto ele : path){
            cout<<ele<<" ";
        }
        cout<<endl;
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