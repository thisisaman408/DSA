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
    int n;
    cin >> n;
    string s; 
    cin >> s;
    int k = 1;
    while (k * k < n)  k++;
    if (k * k > n) {
        cout << "NO"<<endl;
        return;
    }
    for (int i = 0; i < k; ++i) 
    for (int j = 0; j < k; ++j) {
        char c = i == 0 || i == k - 1 || j == 0 || j == k - 1 ? '1' : '0';
        if (s[i * k + j] != c) {
            cout << "NO"<<endl;
            return;
        }
    }
    cout << "Yes\n";

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