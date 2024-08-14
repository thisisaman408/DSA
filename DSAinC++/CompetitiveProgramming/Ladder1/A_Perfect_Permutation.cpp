#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int



void solve(int n,vector<int>&a)
{
    for (int i = 1; i <= n; i++) a[i] = i;
    // for (int i = 1; i <= n; i++) cout<<a[i]<<" ";
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            swap(a[i], a[i + 1]);
            i++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a;
    bool flag = true;
    if (n == 1 or n%2 != 0)
    {
        cout << -1 << endl;
        flag = false;
    }
    if (flag)
    {
        a.resize(n + 1);
        solve(n,a);
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
}
