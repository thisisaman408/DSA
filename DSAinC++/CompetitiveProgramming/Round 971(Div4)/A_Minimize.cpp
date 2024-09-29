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
  int a, b;
  cin >> a >> b;
  cout << abs(a - b) << endl;
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