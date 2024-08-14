#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int x, y, k, ct = 0, p = 1;
        cin >> x >> y >> k;
        vector<pair<int, int>> ans(k);
        if (k & 1)
            ans[ct++] = {x, y}, k--;
        while (k)
        {
            k -= 2;
            ans[ct++] = {x + p, y}, ans[ct++] = {x - p, y};
            p++;
        }
        for (auto &t : ans)
            cout << t.first << " " << t.second << '\n';
    }
}
