/*
For a string of n bits x1, x2, x3 ... Xn the adjacent bit count of the string (AdjBC(x)) is given by

X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn

which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
AdjBC(011101101) = 3
AdjBC(111101101) = 4
AdjBC(010101010) = 0

Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2ⁿ) that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2:
11100, 01110, 00111, 10111, 11101, 11011

Input
The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set is a single line that contains the data set number, followed by a space, followed by a decimal integer giving the number (n) of bits in the bit strings, followed by a single space, followed by a decimal integer (k) giving the desired adjacent bit count. The number of bits (n) will not be greater than 100 and the parameters n and k will be chosen so that the result will fit in a signed 32-bit integer.

Output
For each data set there is one line of output. It contains the data set number followed by a single space, followed by the number of n-bit strings with adjacent bit count equal to k.


https://www.spoj.com/problems/GNYR09F/


*/
#include <iostream>
#include <string.h>

using namespace std;
int dp[105][105][2];
int f(int n, int k, int last)
{
    //here n is no of strings, and k is adjacent bitcount
    if(n == 0) return 0;
    if(n == 1){
        if(k == 0) return 1;
        else return 0;
    }
    if(dp[n][k][last] !=  -1) return dp[n][k][last];

    if(last == 1){
        return dp[n][k][last] = f(n-1,k,0) + f(n-1,k-1,1);
    }
    else
    return dp[n][k][last] = f(n-1,k,0) + f(n-1,k,1);

}


int main()
{

    int t;
    cin>>t;
    while(t--){
        int num,n,k;
        cin>>num>>n>>k;
        memset(dp,-1,sizeof dp);
        int ans = f(n,k,0) + f(n,k,1);
        cout<<num<<" "<<ans<<endl;
    }
}
