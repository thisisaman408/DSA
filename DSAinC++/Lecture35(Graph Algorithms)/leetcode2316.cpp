#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// simple problem of dsu, just create a dsu, and define different connected
// components, you have to focus on the no of elements in a connected component
class Solution {
public:
    int find(unordered_map<int, int>& parent, int val) {
        if (parent[val] != val) {
            parent[val] = find(parent, parent[val]); // Path compression
        }
        return parent[val];
        // this is path compressing, storing the values in the parent[val] in
        // returning
    }

    void Union(unordered_map<int, int>& parent, unordered_map<int, int>& rank, int a, int b) {
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        // can also be solved using dfs, but as edges are given so it's really
        // easy to do it with dsu
        unordered_map<int,int> parent;
        unordered_map<int,int> rank;
        for(int i = 0; i< n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for(auto x : edges){
            int a = x[0];
            int b = x[1];
            Union(parent,rank,a,b);
        }
        //now our unions are made, our connected components are made

        vector<long long> mp(n,0);
        for(int i=0;i<n;i++){
            int root = find(parent,i);
            mp[root]++;
        }
        //i am removing all the zeroes from the solution so that it runs smoothly
        mp.erase(remove(mp.begin(),mp.end(),0),mp.end());
        //now we have size of each connected component too in our map
        long long ans = 0;
        vector<long long> helper = mp;
        for(int i = mp.size()-2;i>=0;i--){
            mp[i] += mp[i+1];
        }
        for(int i = helper.size()- 2; i>=0; i--){
            ans += helper[i]*mp[i+1];
        }
        if(ans== 1) return 0;
        return ans;
    }
};

int main(){
    Solution sol;
    int n = 7;
    vector<vector<int>> edges = {{0,2},{0,5}, {2,4},{1,6}};
    cout<<sol.countPairs(n,edges)<<endl;
}