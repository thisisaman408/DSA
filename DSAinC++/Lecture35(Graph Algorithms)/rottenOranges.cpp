#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // here our goal will be to start bfs from every rotten oranges,
        int freshOranges = 0;
        int mins = 0; // this is our answer, after each bfs we will increment it
        queue<pair<int, int>> rotten; // queue uski banti hai, jisse bfs shuru krna hota hai,
        // so hame sare rotten se shuru krna hai, jaise, pacificAtlantic wale m
        // 2 queue bana kar kiya tha

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    freshOranges++;
                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        // make a direction vector for bfs
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // now start bfs
        while (!rotten.empty() && freshOranges > 0) {
            int size = rotten.size();
            //i first tried to directly use rotten.size() below, but, see the size of the rotten is increasing as we rott the other oranges, 
            //try removing it(size) and using rotten.size(), a test case will fail, dry run that you will get!
            for (int p = 0; p < size; p++) {
                auto x = rotten.front();
                rotten.pop();

                int i = x.first;
                int j = x.second;

                for (int d = 0; d < 4; d++) {
                    int newR = i + dir[d].first;
                    int newC = j + dir[d].second;
                    if (newR < 0 || newC < 0 || newR >= rows or newC >= cols or grid[newR][newC] == 2 or grid[newR][newC] == 0) continue;
                    grid[newR][newC] = 2;
                    freshOranges--;
                    rotten.push({newR, newC});
                }
            }
            mins++;
        }

        return freshOranges == 0 ? mins : -1;
    }
};


int main(){

     Solution sol;
     vector<vector<int>> grid = {{2,1,1}, {1,1,0}, {0,1,1}};
     cout<<sol.orangesRotting(grid)<<endl;

}