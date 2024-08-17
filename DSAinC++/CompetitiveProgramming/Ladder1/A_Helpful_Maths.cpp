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
    string s;
    cin>>s;
    s.erase(remove(s.begin(),s.end(),'+'), s.end());
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        cout<<s[i];
        if(i == s.size() -1) continue;
        else cout<<'+'; 
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   
   solve();

    return 0;
}