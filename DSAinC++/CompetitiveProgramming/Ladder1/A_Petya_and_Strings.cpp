#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include<cstring>
#include<string.h>
#include<cctype>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int

void solve() {
    string s;
    string y;
    cin>>s>>y;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    transform(y.begin(),y.end(),y.begin(),::tolower);

    if(s<y)cout<<-1<<endl;
    else if(s>y) cout<<1<<endl;
    else cout<<0<<endl;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}