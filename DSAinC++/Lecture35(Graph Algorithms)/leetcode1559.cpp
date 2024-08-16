#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    int rows, cols;
    vector<vector<bool>> visited;

    bool dfs(vector<vector<char>> &grid, int i, int j, int pi, int pj)
    {
        visited[i][j] = true;

        // Define possible directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto [dx, dy] : directions)
        {
            int ni = i + dx;
            int nj = j + dy;

            // Ensure the neighbor is within bounds
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
            {
                // Ensure the neighbor has the same character
                if (grid[ni][nj] == grid[i][j])
                {
                    // If the neighbor is the parent cell, continue
                    if (ni == pi && nj == pj)
                        continue;

                    // If the neighbor is visited and is not the parent, a cycle is found
                    if (visited[ni][nj])
                        return true;

                    // Recursively perform DFS on the neighbor
                    if (dfs(grid, ni, nj, i, j))
                        return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        visited.resize(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!visited[i][j])
                {
                    // Perform DFS to detect cycles starting from each unvisited cell
                    if (dfs(grid, i, j, -1, -1)) return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> grid = {{'a', 'a', 'a', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'a', 'a', 'a'}};
    cout << sol.containsCycle(grid) << endl;
}