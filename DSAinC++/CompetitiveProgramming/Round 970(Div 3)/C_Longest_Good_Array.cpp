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

//solved by Aman -> thisisaman408

#define ll long long
#define lli long long int

void solve() {
  int l,r;
  cin>>l>>r;
    int x = r - l;
    int cl = 0, cr = 1000001;
    while (cr - cl > 1) {
        int cm = (cl + cr) >> 1;
        if (1ll * cm * (cm - 1) / 2 <= x)  cl = cm;
        else   cr = cm;
    }
    cout << cl <<endl;
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