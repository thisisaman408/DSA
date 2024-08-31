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

#define ll long long
#define lli long long int

/*

this is the correct appraoch

The problem can be rephrased as follows: the first player can remove a number adjacent to a larger number, while the second player can remove a number adjacent to a smaller number.

To maximize the value of the last remaining number, in the 𝑖
-th round of the first player's moves, he will remove the 𝑖
-th smallest number in the sequence, and this is always achievable. Similarly, in the 𝑖
-th round of the second player's moves, he will remove the 𝑖
-th largest number.

Thus, the answer is the ⌊𝑛2⌋+1
-th smallest number in the original sequence.

Time complexity: 𝑂(𝑛log𝑛)
 per test case.

*/
void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (n % 2 == 1) cout << a[(n - 1) / 2] << endl;
  else cout << a[n / 2] << endl;
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