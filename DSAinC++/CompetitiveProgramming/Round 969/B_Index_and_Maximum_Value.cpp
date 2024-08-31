#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cstring>
#include <string.h>
//solved by Aman -> thisisaman408
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int

void solve()
{
  int n, q;
  cin >> n >> q;
  int aman = 0;
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    aman = max(aman, x);
  }
  while (q--)
  {

    char c;
    int l, r;
    cin >> c >> l >> r;
    if (l <= aman && aman <= r)
    {

      if (c == '-')  aman--;
      else aman++;
    }

    cout << aman<< " ";
  }
  cout<<endl;
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