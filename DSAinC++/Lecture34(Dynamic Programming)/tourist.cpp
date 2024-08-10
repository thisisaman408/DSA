/*


A lazy tourist wants to visit as many interesting locations in a city as possible without going one step further than necessary. Starting from his hotel, located in the north-west corner of city, he intends to take a walk to the south-east corner of the city and then walk back. When walking to the south-east corner, he will only walk east or south, and when walking back to the north-west corner, he will only walk north or west. After studying the city map he realizes that the task is not so simple because some areas are blocked. Therefore he has kindly asked you to write a program to solve his problem.

Given the city map (a 2D grid) where the interesting locations and blocked areas are marked, determine the maximum number of interesting locations he can visit. Locations visited twice are only counted once.
Input
The first line in the input contains the number of test cases (at most 20). Then follow the cases. Each case starts with a line containing two integers, W and H (2 ≤ W , H ≤ 100), the width and the height of the city map. Then follow H lines, each containing a string with W characters with the following meaning:

. Walkable area
* Interesting location (also walkable area)
# Blocked area

You may assume that the upper-left corner (start and end point) and lower-right corner (turning point) are walkable, and that a walkable path of length H + W − 2 exists between them.
Output
For each test case, output a line containing a single integer: the maximum number of interesting locations the lazy tourist can visit.

https://www.spoj.com/problems/TOURIST/

*/

/*
we will take two tourist, and we will check all the posibilities of those two tourist, 
for dp, we will initialise a 3d dp, although it seems like the dp should be of 4 dimensions, but actually
we can derive te 4th index by the rest of the 3 indexes
as each step we are either increasing one or another,
so alwasys at each step,

x + y = i+j,

so if we know the 3 variables, we can easily calcute the 4th variable

*/

#include <iostream>
#include<vector>
#include<cstring>
#include<climits>
#define ll long long int
using namespace std;

ll m,n; //dimensions of matrices, rows*colums

char mat[105][105];

ll dp[105][105][105];

ll f(int i  ,int j ,int x, int y){
    if(x > m or y > n or i>m or j>n or mat[i][j] == '#' or mat[x][y] == '#') return 0;//out of bound and restriced areas, so return 0
    if(i == m and j == n){ 
        //now here, the tourist 1 is at mat[m][n], but think where could be tourist 2?
        //might be that both together came down, but still interestin place will be takes once
        //toursit 2 maybe on the right(which is out of bound, so not considered)
        //here i am just explaining that it is not possible that tourist 1 has reahed m,n but tourist 2 hasn't 
        //it is only possible when tourist 2 has crossed the grid(i +j == n+m, no other cell can have sums equal to n+m, inside the grid)
        return(mat[i][j] == '*');
     }
    if(dp[i][j][x] != -1) return dp[i][j][x];
    ll result = INT_MIN;
    result = max(result, f(i+1,j,x+1,y));
    result = max(result, f(i+1,j,x,y+1));
    result = max(result, f(i,j+1,x+1,y));
    result = max(result, f(i,j+1,x,y+1));

    //now it might be possible that the current location is also interesting location
    
    result += (mat[i][j] == '*');
    result += (mat[x][y] == '*');
    //now if both are looking the same index, so we should avoid repetation

    if(i == x and j == y and mat[i][j] == '*') result--;
    return dp[i][j][x] = result;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(dp,-1,sizeof dp);
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n;j++){
                cin>> mat[i][j];
            }
        }
        cout<<f(1,1,1,1)<<endl;
    }
    
    
    return 0;
}
// in this quesion, there is col*rows, i mean first col are getting input and then rows, else question is simple