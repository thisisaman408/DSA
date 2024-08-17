#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include<cstring>
#include<string.h>

using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int

void solve() {
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int x = s.size();
        if(x > 10){
            int a = x -2;
            cout<<s[0]<<a<<s[x-1]<<endl;
        }
        else cout<<s<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}