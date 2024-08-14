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

int a, b, n;
string solve()
{
    string ans = to_string(a);
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int d = 1; d <= 9; d++) {
            string temp = ans + to_string(d);
            if (stoi(temp) % b == 0) {
                ans = temp;
                found = true;
                break;
            }
        }
        if (!found) {
            return "-1"; 
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> n;
   string result = solve();
    cout << result << endl;

    return 0;
}