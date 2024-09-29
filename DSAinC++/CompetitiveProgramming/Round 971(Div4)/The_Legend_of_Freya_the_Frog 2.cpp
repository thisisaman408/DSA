#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cstring>
#include <string.h>

using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// solved by Aman -> thisisaman408

#define ll long long
#define lli long long int

void solve()
{
  ll x, y, k;
  cin >> x >> y >> k;
  // ll x_moves = (x + k - 1) / k;
  // ll y_moves = (y + k - 1) / k;
  ll moves = (x+y)/k;
  if(x+y%k!=0) moves++;
  cout<<moves<<endl;
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