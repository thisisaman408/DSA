#include <iostream>
using namespace std;

void move(int &i, int &j, char arr[][100], int m, int n) {
    if (arr[i][j] == 'L') j--;
    else if (arr[i][j] == 'R') j++;
    else if (arr[i][j] == 'U') i--;
    else i++;
}

int main() {
    int m, n;
    cin >> m >> n;
    char arr[100][100];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)  cin >> arr[i][j];
    int x, y;
    cin >> x >> y;
    if (x < 0 || y < 0 || x >= m || y >= n) { cout << false; return 0;}
    int slowX = x, slowY = y;
    int fastX = x, fastY = y;
    while (true) {
        move(slowX, slowY, arr, m, n);
        move(fastX, fastY, arr, m, n);
        if (fastX < 0 || fastY < 0 || fastX >= m || fastY >= n) { cout << false; return 0;}
        move(fastX, fastY, arr, m, n);
        if (fastX < 0 || fastY < 0 || fastX >= m || fastY >= n) {cout << false; return 0;}
        if ((slowX == m - 1 && slowY == n - 1) || (fastX == m - 1 && fastY == n - 1)) { cout << true; return 0;}
        if (slowX == fastX && slowY == fastY) {  cout << false; return 0;}
        if (slowX < 0 || slowY < 0 || slowX >= m || slowY >= n)  { cout << false; return 0;}
    }

    return 0;
}
