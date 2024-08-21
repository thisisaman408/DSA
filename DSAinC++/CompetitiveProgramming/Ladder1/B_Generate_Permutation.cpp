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
    cin >> n;

    if (n % 2 == 0)   cout << -1 << endl;
    else {
        vector<int> perm;
        int left = 1, right = n;
        while (left <= right) {
            perm.push_back(left++);
            if (left <= right) {
                perm.push_back(right--);
            }
        }

        for (int x : perm) {
            cout << x << " ";
        }
        cout << endl;
    }
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