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
unordered_map<char,int> mp;
unordered_map<char,int>sp;
void solve() {
    string a;
    string b;
    string c;
    cin>>a>>b>>c;
    if(a.size() + b.size() != c.size()){
        cout<<"NO"<<endl;
        return;
    }
    for(int i =0; i<a.size();i++){
        mp[a[i]]++;
    }
    for(int i =0; i<b.size();i++){
        mp[b[i]]++;
    }
    for(int i =0; i<c.size();i++){
        sp[c[i]]++;
    }
    for(auto x : mp){
        char ch = x.first;
        if((sp.find(ch) == sp.end()) or (sp.find(ch) !=sp.end() and sp[ch] != mp[ch])) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}