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
  int n;
  cin >> n;
  int aman = 0;
  int x, y;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x>>y;
    if (y == 1) aman++;
  }
  cout<<2*aman<<endl;
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