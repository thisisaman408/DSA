#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//https://leetcode.com/problems/surrounded-regions/description/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int rows = board.size();
        int cols = board[0].size();

        // Directions for moving in the matrix: right, down, left, up
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // BFS to mark boundary-connected 'O's
        queue<pair<int, int>> q;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && board[r][c] == 'O') {
                    q.push({r, c});
                    board[r][c] = 'E'; // 'E' stands for 'escaped' or boundary-connected
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'O') {
                    board[nr][nc] = 'E'; // Mark as boundary-connected
                    q.push({nr, nc});
                }
            }
        }

        // Convert all 'O's to 'X' (surrounded regions) and 'E's back to 'O'
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'E') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};

int main(){


    Solution sol;
    vector<vector<char>> board = {{'X', 'X','X','X'}, {'X', 'O', 'O', 'X'} ,{'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    sol.solve(board);
    for(int i = 0; i< board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}