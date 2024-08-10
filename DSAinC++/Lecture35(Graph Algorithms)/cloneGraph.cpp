#include<iostream>
#include<vector>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    vector<Node*> nodeRegister;
    void dfs(Node* actual, Node* clone){
        for(auto x : actual->neighbors){
            if(!nodeRegister[x->val]){
                //if the value of nodeRegister at the index of neighbor value is NULL, then create a new Node
                Node* newNode = new Node(x->val);
                //add it's address to nodeRegister
                nodeRegister[newNode->val] = newNode;
                //add it in the neighbor of clone
                clone->neighbors.push_back(newNode);
                //call the dfs to new node and it's new clone ndoe
                dfs(x,newNode);
                //neighbor of actual node is the new actual node, and it's copy is newNode
            }
            else{
                //we just have to add this current neighbor in the neighbors of clone node
                clone->neighbors.push_back(nodeRegister[x->val]);
                //we have to add the address, so if neighbor is already there in the nodeRegister
                //so we will get it's address from there, and add it to the clone
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* clone = new Node(node->val);
        nodeRegister.resize(110,NULL);//resize it, to maximum possible nodes
        nodeRegister[clone->val] = clone;
        dfs(node, clone);
        return clone;
    }
};

int main(){
    
}