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
    int x = 0;
    while (n--)
    {
        string s;
        cin>>s;
        if(s == "X++" or s == "++X") x++;
        else if(s == "--X" or s == "X--")x--;
    }
    cout<<x<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}