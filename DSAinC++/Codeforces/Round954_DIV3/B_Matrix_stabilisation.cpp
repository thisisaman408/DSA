#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Cell {
    int row;
    int col;
    bool operator<(const Cell& other) const {
        if (row != other.row) return row < other.row;
        return col < other.col;
    }
};

bool isLocalMax(const vector<vector<int>>& aman, int i, int j, int n, int m) {
    int val = aman[i][j];
    if (i > 0 && aman[i-1][j] >= val) return false;
    if (i < n-1 && aman[i+1][j] >= val) return false;
    if (j > 0 && aman[i][j-1] >= val) return false;
    if (j < m-1 && aman[i][j+1] >= val) return false;
    return true;
}

void stabilizeMatrix(vector<vector<int>>& aman, int n, int m) {
    set<Cell> toCheck;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (isLocalMax(aman, i, j, n, m)) {
                toCheck.insert({i, j});
            }
        }
    }

    while (!toCheck.empty()) {
        set<Cell> nextCheck;
        for (const auto& cell : toCheck) {
            int i = cell.row;
            int j = cell.col;
            if (isLocalMax(aman, i, j, n, m)) {
                aman[i][j] -= 1;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (abs(di) + abs(dj) != 1) continue;
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            nextCheck.insert({ni, nj});
                        }
                    }
                }
            }
        }
        toCheck = nextCheck;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> aman(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> aman[i][j];
            }
        }

        stabilizeMatrix(aman, n, m);

        for (const auto& row : aman) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
