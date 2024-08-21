#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include<cstring>
#include<string.h>
#include<unordered_map>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int


void solve() {
    unordered_map<int, int> a;
    int n;
    cin>>n; //size of the array
    for(int i = 0;i <n;i++) {
        int x;
        cin>>x;
        a[x]++;
    }
    int maxFreq = 1;

    for (const auto& entry : a) {
        if (entry.second > maxFreq) {
            maxFreq = entry.second;
        }
    }
    // cout<<"This is Freq  : "<<maxFreq<<endl;
    cout<<(n-maxFreq)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin>>t;  
    while(t--) {
        solve();
    }

    return 0;
}