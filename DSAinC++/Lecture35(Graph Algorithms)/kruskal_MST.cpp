#include<iostream>
using namespace std;
//in an undirected connected and weighted graph, we have to find an special subtree, 
/*

which has, 
tree means no cycle, 

the subtree is a subgraph of our given graph

this subgraph must contains all the vertices of the graph
(all edges might not be taken )



There must be only exclusive path from one node to every other node.


There can be many subgraphs like this of a particular graph
in our this special subtree of subgraph,
the subgraph is of minimum weight among all such subgraphs






THIS SPECIAL TREE IS CALLED MINIMUM SPANNING TREE (MST)


- Tree, thus no cycles
- includes all the nodes of the graph
- sum of the edges weight is minimum 

we can find a MST, using kruskal and prim's algo

both are GREEDY algo !!!!!!!



if you see the name 
which is minimum spanning tree
tree means a subgraph

spanning means

minimum edges required to just connect the graph
*/

/*
Kruskal's


One by One keep a picky edge with minimum weight
if picking a particular edge creates a cycle, AVOID IT, else choose it



I am given a edge list,
Here,
I am gonna sort the edge list first
now we have to detect a cycle, and edge list is given,it's really easy if we use DSU
*/


#include<iostream>
#include<vector>

using namespace std;


int main(){
    
}