#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

// this solution is wrong right now

using namespace std;

int countBrilliantSubarrays(const vector<int> &a)
{
  int n = a.size();
  int result = 0;
  for (int start = 0; start < n; ++start)
  {
    unordered_set<int> elements;
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int end = start; end < n; ++end)
    {
      elements.insert(a[end]);
      minVal = min(minVal, a[end]);
      maxVal = max(maxVal, a[end]);
      if (maxVal - minVal + 1 == elements.size())
      {
        result++;
      }
    }
  }

  return result;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
    }

    cout << countBrilliantSubarrays(a) << endl;
  }

  return 0;
}
