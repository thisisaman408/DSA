#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int cc = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '0')
                    continue;
                cc++;
                grid[r][c] = '0'; // marked
                queue<pair<int, int>> q;
                q.push({r, c});
                while (!q.empty())
                {
                    auto x = q.front();
                    q.pop();
                    int ro = x.first;
                    int co = x.second;
                    // check up
                    if (ro - 1 >= 0 && grid[ro - 1][co] == '1')
                    {
                        q.push({ro - 1, co});
                        grid[ro - 1][co] = '0';
                    }
                    // down
                    if (ro + 1 < grid.size() && grid[ro + 1][co] == '1')
                    {
                        q.push({ro + 1, co});
                        grid[ro + 1][co] = '0';
                    }
                    // left
                    if (co - 1 >= 0 && grid[ro][co - 1] == '1')
                    {
                        q.push({ro, co - 1});
                        grid[ro][co - 1] = '0';
                    }
                    // right
                    if (co + 1 < grid[0].size() && grid[ro][co + 1] == '1')
                    {
                        q.push({ro, co + 1});
                        grid[ro][co + 1] = '0';
                    }
                }
            }
        }
        return cc;
    }
};
int main()
{
    
}