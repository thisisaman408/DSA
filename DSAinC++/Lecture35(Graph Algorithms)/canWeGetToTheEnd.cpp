#include <iostream>

using namespace std;

/*

our question is,
we are given a grid of n*m dimension,
now, each cell there is written L,R,U,D

so now, at each cell whatever is written you can go to only that direction

your task is to determine if you are at currently i,j, so can you reach n-1 and m-1

Constraints are that you have to use O(1) tc
and grid is non modifiable

*/
int main()
{
    int m, n;
    cin >> m>>n;
    char arr[m][n];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
    int i, j;
    cin >> i >> j;
    int steps = 0;
    bool flag = true;
    while(steps < m*n){
        if(i == m -1 and j == n-1) {cout<<1; flag = false; break;}
        if(arr[i][j] == 'L') j--;
        else if(arr[i][j] == 'R') j++;
        else if(arr[i][j] == 'U') i--;
        else i++;

        if (i < 0 || i >= n || j < 0 || j >= m) break;
        steps++;
    }
    if(flag)cout<<0;
}