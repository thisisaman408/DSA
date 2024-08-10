#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

//https://leetcode.com/problems/shortest-bridge/

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
        int n = grid.size();
        stack<pair<int, int>> stk;
        stk.push({r, c});
        
        while (!stk.empty()) {
            auto [cr, cc] = stk.top();
            stk.pop();
            
            if (cr < 0 || cr >= n || cc < 0 || cc >= n || visited[cr][cc] || grid[cr][cc] == 0) {
                continue;
            }
            
            visited[cr][cc] = true;
            q.push({cr, cc});
            
            for (auto& dir : directions) {
                stk.push({cr + dir[0], cc + dir[1]});
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        bool found = false;
        
        // Find the first island using DFS and mark it
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid, i, j, visited, q);
                    found = true;  // We have found and marked the first island
                }
            }
        }
        //by above dfs, what we are actually doing is
        /*
            we are checking if the current i,j is visited or not, if it's not visited, then make a dfs from it

            now we are doing dfs for i,j

            so, in the dfs function, the function is basically, checking the connected components,
            and returning all the elements of first island in the queue, 
            so now, below i will make a bfs from each element of first island,
            and increment by 1 , each time i get a 0,

            and this found is used, cause once we get all the elements of a connected component, we will not check for another island,
        */
        
        // BFS to find the shortest bridge
        int bridgeLength = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                
                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == 1 && !visited[nr][nc]) {
                            return bridgeLength;
                        }
                        if (grid[nr][nc] == 0 && !visited[nr][nc]) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            bridgeLength++;
            //we are incrementing bridgelength as soon as our first bfs call ends, basically first layer ends
        }
        
        return -1;  // Just a fallback in case something goes wrong
    }
};

int main(){

    Solution sol;
    vector<vector<int>> x = {{1,1,1,1,1}, {1,0,0,0,1}, {1,0,1,0,1}, {1,0,0,0,1}, {1,1,1,1,1}};
    cout<<sol.shortestBridge(x)<<endl;
}

