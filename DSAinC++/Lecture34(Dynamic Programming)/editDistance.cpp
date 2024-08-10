//https://leetcode.com/problems/edit-distance/submissions/1341715930/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
int dp[505][505];
class Solution {
public:
    
    int f(string& a, string& b, int i, int j){
        if(i == a.size()) return dp[i][j] = b.size() -j;
        if(j == b.size()) return dp[i][j] = a.size()- i;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) return dp[i][j] = f(a,b,i+1,j+1);
        return dp[i][j] = min({1+f(a,b,i+1,j+1), 1+f(a,b,i+1,j), 1+ f(a,b,i,j+1)});
        //cases are as replacement, deletion, insertion

    }
    int minDistance(string &word1, string& word2) {
        memset(dp,-1,sizeof dp);
        return f(word1,word2,0,0);
    }
};

int main(){
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";
    cout<<sol.minDistance(word1,word2)<<endl;
}