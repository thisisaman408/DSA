#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// https://leetcode.com/problems/01-matrix/description/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize BFS queue with all zero cells and set their distance to 0
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        // Directions for moving in the matrix: right, down, left, up
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && ans[nr][nc] == INT_MAX) {
                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};


int main(){
    Solution sol;

    vector<vector<int>> mat = {{0,0,0}, {0,1,0}, {1,1,1}};
    vector<vector<int>>ans = sol.updateMatrix(mat);
    for(int i =0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}