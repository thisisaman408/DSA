#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cstring>
#include <string.h>
#include<string>
#include <unordered_set>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int

/*

A necessary condition for 𝑠
 to be good is that 𝑠1≠𝑠𝑛
. For a string 𝑠
 where 𝑠1≠𝑠𝑛
, let 𝑡1
 be a string composed of just the single character 𝑠1
, and let 𝑡2
 be a string composed of the 𝑛−1
 characters from 𝑠2
 to 𝑠𝑛
. In this way, the condition is satisfied.

Therefore, if 𝑠1≠𝑠𝑛
, the answer is "Yes"; otherwise, the answer is "No".

Time complexity: 𝑂(𝑛)
 per test case

*/

//this is the best solution ,my solution you can check on codeforces, mine was a bit lengthy

void solve() {
    string s;
    int n;
    cin >> n >> s;

    if(s[0] != s[n-1]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}