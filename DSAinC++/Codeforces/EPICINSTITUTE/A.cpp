#include <iostream>
#include <vector>
#include <unordered_set>
#include<queue>
using namespace std;

// Function to get unique colors using a DP approach
int getUniqueColors(int n, int m, int k) {
    // DP table to store the color number for each cell
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    // Initialize color counter
    int color = 1;
    
    // Set to store unique colors
    unordered_set<int> uniqueColors;
    
    // Process each cell
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == 0) {
                // Start a new color spread
                int curColor = color++;
                uniqueColors.insert(curColor);
                
                // Use BFS to fill the color
                queue<pair<int, int>> q;
                q.push({i, j});
                dp[i][j] = curColor;
                
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    
                    vector<pair<int, int>> directions = {{k, 0}, {-k, 0}, {0, k}, {0, -k}};
                    
                    for (const auto& dir : directions) {
                        int newX = x + dir.first;
                        int newY = y + dir.second;
                        
                        if (newX >= 0 && newY >= 0 && newX < n && newY < m && dp[newX][newY] == 0) {
                            dp[newX][newY] = curColor;
                            q.push({newX, newY});
                        }
                    }
                }
            }
        }
    }
    
    // The size of the uniqueColors set is the number of unique colors
    return uniqueColors.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        cout << getUniqueColors(n, m, k) << endl;
    }

    return 0;
}
