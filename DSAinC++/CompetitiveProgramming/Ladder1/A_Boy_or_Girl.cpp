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

unordered_set<int> aman;
void solve() {
  string s;
  cin>>s;
  for(int i = 0; i< s.size(); i++) aman.insert(s[i]);
  if(aman.size()%2 != 0) cout<<"IGNORE HIM!"<<endl;
  else cout<<"CHAT WITH HER!"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}