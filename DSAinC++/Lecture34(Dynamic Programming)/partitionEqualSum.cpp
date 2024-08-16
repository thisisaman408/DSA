#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include<cstring>
#include<string.h>
#include<numeric> //to use accumulate

using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) return false;
        int x = sum/2;
        vector<bool> d(x + 1, false);
        d[0] = true;
        for(int a : nums)  for(int u = x; u >= a ;u--) d[u] = d[u] || d[u-a];
        return d[x];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   Solution sol;
   vector<int> nums = {1,5,11,5};
    bool ans =  sol.canPartition(nums);
    if(ans) cout<<"Yes, it can be partitioned"<<endl;
    else cout<<"No, it cannot be partitioned"<<endl;
    return 0;
}