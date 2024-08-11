//here we will use union by rank technique, in which we will create a tree like structure to
//establish parent child relationship

/*
Here, we call it rank by union, because here,
everytime we add a new link of one group's parent to the other group's
parent, this link is called rank,
and guess how many times do we have to create this link???
logn, how? cause, jitni bar, previous approach m koi ek particular element
change ho rha tha, utni bar hi yaha ye rank banegi,




Now,
we don't have to create a size array, we will create this rank array,
which will store the rank of each element, 
initial rank of each element is 1

rank is basically, how many operations it will take an element to reach to it's parent
which is simply the no of  recursive call needed to find it's parent in the find function,

and everytime an elememt of a group is added to some other element of the other group

then we will just increment the rank of that index, of that element




we will do this with, union by rank + path compression

*/


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int find(unordered_map<int,int>& parent, int val){
   if (parent[val] != val) {
        parent[val] = find(parent, parent[val]); // Path compression
    }
    return parent[val];
    //this is path compressing, storing the values in the parent[val] in returning
}


void Union(unordered_map<int,int>& parent, unordered_map<int,int>& rank, int a,int b){
    int rootA = find(parent, a);
    int rootB = find(parent, b);
    
    if (rootA != rootB) {
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    // Initialize parent and rank for the first n elements
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    while (m--) {
        cout<<"Enter your operation : ";
        string query;
        cin >> query;
        if (query == "union") {
            int a, b;
            cin >> a >> b;
            if (parent.find(a) == parent.end()) {
                parent[a] = a;
                rank[a] = 0;
            }
            if (parent.find(b) == parent.end()) {
                parent[b] = b;
                rank[b] = 0;
            }
            Union(parent, rank, a, b);
        } else if (query == "find") {
            int x;
            cin >> x;
            if (parent.find(x) == parent.end()) {
                parent[x] = x;
                rank[x] = 0;
            }
            cout << find(parent, x) << endl;
        }
    }

    return 0;
}
/*
this is the perfect code,

here try this
6 8
then do m-1 union queiries of

1 3
3 5
2 5
8 7
4 9
9 1
2 6
then find 7,you will get 8

then check 3 you will get 4



*/


// inverse ackermann function, is used to calculate it's tc
/*

it's comes out to be log*n, 
what does this mean??
how many operations of logn should be applied on n to make it less than 1
for example i have 65536 which is 2^16
so n = 65536
logn = 16
logn = 4
logn = 2
logn = 1
logn = 0

so it took me 5 operations
this 5 is the value of log*65536

let's check for 18446744073709551616 which is 2^64
n = 18446744073709551616
logn = 64
logn = 6
logn = 2.5(say)
logn = 1.1 something
logn = 0
again took me 5 seconds, 


so isn't this amazing time complexity???
nearly constant



so after path compression

the tc of the algo of union rank + path compression becomes
log*n from logn
*/
