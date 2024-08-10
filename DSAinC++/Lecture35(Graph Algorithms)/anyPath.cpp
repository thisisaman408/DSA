#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>

using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;


void add_edge(int s, int d, bool bi_dir = true){
    graph[s].push_back(d);
    if(bi_dir) graph[d].push_back(s);
}

//tc of dfs is O(V+E), V-> no of vertices, E-> no of edges
//sc O(V)
bool dfs(int curr,int end){
    if(curr == end) return true;
    visited.insert(curr);// mark it visited
    for(auto neighbour : graph[curr]){
        if(!visited.count(neighbour)){// if the curr is not in visited, then we will check for it's neighbour
            bool result = dfs(neighbour,end);
            if(result) return true;
        }
    }
    return false;
}


bool anyPath(int start, int end){
    visited.clear();
    return dfs(start,end);
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
    cout<<"Now enter the two vertices between which you want to check if path exist or not"<<endl;
    cin >> x >> y;

    display(); // Display the graph
    cout << endl;
    cout << (anyPath(x, y) ? "Path exists" : "No path exists") << endl; // Check for any path and output result
}
