#include <iostream>
#include <vector>
#include <queue>

//https://leetcode.com/problems/pacific-atlantic-water-flow/description/

using namespace std;

class Solution
{
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows;
    int cols;
    vector<vector<int>> h;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        rows = heights.size();
        cols = heights[0].size();
        h = heights;
        queue<pair<int, int>> pacificbfs;
        queue<pair<int, int>> atlanticbfs;

        // adding the boundary cells to pacific and atlantic to start multisource bfs
        for (int r = 0; r < rows; r++)
        {
            pacificbfs.push({r, 0});
            atlanticbfs.push({r, cols - 1});
        }
        for (int i = 1; i < cols; i++) pacificbfs.push({0, i});
        for (int i = 0; i < cols - 1; i++) atlanticbfs.push({rows - 1, i});

        vector<vector<bool>> pacific = bfs(pacificbfs);
        vector<vector<bool>> atlantic = bfs(atlanticbfs);

        vector<vector<int>> result;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (pacific[i][j] and atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
    vector<vector<bool>> bfs(queue<pair<int, int>> &q)
    {
        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            int i = x.first;
            int j = x.second;
            visited[i][j] = 1;
            for (int d = 0; d < 4; d++)
            {
                int newR = i + dir[d].first;
                int newC = j + dir[d].second;

                if (newR < 0 or newC < 0 or newR >= rows or newC >= cols) continue;
                if (visited[newR][newC]) continue;
                if (h[newR][newC] < h[i][j]) continue;
                q.push({newR, newC});
            }
        }
        return visited;
    }
};

int main()
{

    vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    Solution sol;
    vector<vector<int>> result = sol.pacificAtlantic(heights);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}