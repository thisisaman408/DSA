#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Check if all elements are the same
    bool all_same = true;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[0])
        {
            all_same = false;
            break;
        }
    }

    if (all_same)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    int first = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[0])
        {
            cout << 1 << " " << i + 1 << endl;
            first = i;
        }
    }

    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[0])
        {
            cout << first + 1 << " " << i + 1 << endl;
        }
    }
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
