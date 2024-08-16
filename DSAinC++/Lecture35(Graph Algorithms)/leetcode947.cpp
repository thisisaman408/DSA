#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


//simply solve it using, dfs and calculate the no of elements in a single connected component
//and two elements are in same row or column, then these are single connected component
//subtract it from total no of nodes


class Solution {
public:
int n;
    void dfs(int i, unordered_set<int>& visited, vector<vector<int>>& stones){
        visited.insert(i);
        for(int u = 0; u < n; u++){
            if(!visited.count(u)){
                if(stones[i][0] == stones[u][0] or stones[i][1] == stones[u][1]){
                    dfs(u,visited,stones);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        n = stones.size();
        unordered_set<int> visited;
        int count =0;
        for(int i=0; i< n;i++){
            if(!visited.count(i)) {
                dfs(i, visited,stones);
                count++;
            }
        }
        cout<<count<<endl;
        return n - count;
    }
};

int main(){

    vector<vector<int>> stones = {{0,0}, {0,1},{1,0},{1,2}, {2,1}, {2,2}};
    Solution sol;
    cout<<sol.removeStones(stones)<<endl;

}