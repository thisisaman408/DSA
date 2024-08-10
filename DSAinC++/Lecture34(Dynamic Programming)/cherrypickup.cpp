//similar problem to tourist, just changed the code of tourist a bit, to match the requirements of leetcode

//https://leetcode.com/problems/cherry-pickup/


#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define ll long long int
 ll n;
vector<vector<int>> mat;
ll dp[55][55][55];
int neg = INT_MIN;
class Solution {
public:
    ll f(int i, int j, int x, int y) {
        if (x > n or y > n or i > n or j > n or mat[i][j] == -1 or
            mat[x][y] == -1) return neg;
        if (i == n and j == n) return (mat[i][j] == 1);
        if (dp[i][j][x] != -1)  return dp[i][j][x];
        ll result = neg;
        result = max(result, f(i + 1, j, x + 1, y));
        result = max(result, f(i + 1, j, x, y + 1));
        result = max(result, f(i, j + 1, x + 1, y));
        result = max(result, f(i, j + 1, x, y + 1));

        if(result == neg) return dp[i][j][x] = neg;
        result += (mat[i][j] == 1);
        result += (mat[x][y] == 1);

        if (i == x and j == y and mat[i][j] == 1) result--;
        return dp[i][j][x] = result;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp,-1,sizeof(dp));
        mat.clear();
        mat.resize(n+5,vector<int>(n+5,0));
        for(int i = 0; i<n;i++){
            for(int j = 0; j< n;j++){
                mat[i+1][j+1] = grid[i][j];
            }
        }
        ll ans = f(1,1,1,1);
        return ans == neg? 0 : ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{0,1,-1},{1,0,-1},{1,1,1}};
   
    cout<<sol.cherryPickup(grid)<<endl;

}
