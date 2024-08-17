#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include<cstring>
#include<string.h>
#include<unordered_set>

using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int
unordered_set<int>aman;
void solve() {
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   aman.insert(a);
   aman.insert(b);
   aman.insert(c);
   aman.insert(d);
//    cout<<aman.size()<<endl;
   cout<<(4 - aman.size());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}