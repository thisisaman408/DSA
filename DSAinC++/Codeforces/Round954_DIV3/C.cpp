#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // Include this header for std::pair
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> indices(m);
    vector<char> chars(m);

    for (int i = 0; i < m; ++i)
    {
        cin >> indices[i];
        --indices[i]; // Convert to 0-based index
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> chars[i];
    }

    // Create a vector of pairs to store indices and corresponding characters
    vector<pair<int, char>> updates;
    for (int i = 0; i < m; ++i)
    {
        updates.push_back({indices[i], chars[i]});
    }

    // Sort the updates based on characters first, then indices
    sort(updates.begin(), updates.end(),  {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    // Apply the sorted characters to the sorted indices
    for (int i = 0; i < m; ++i)
    {
        s[updates[i].first] = updates[i].second;
    }

    cout << s << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
