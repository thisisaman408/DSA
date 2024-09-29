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
vector<int> aman;

void solve()
{
  aman.clear();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= 4; j++)
    {
      char x;
      cin >> x;
      if (x == '#')
      {
        aman.push_back(j);
      }
    }
  }
  reverse(aman.begin(), aman.end());

  for (int i = 0; i < aman.size(); i++)
  {
    cout << aman[i] << " ";
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