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

int n;
bool flag = true;
void solve()
{
    int bal25 = 0, bal50 = 0; 
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x == 25) bal25 += 25;
        else if (x == 50) {
            if (bal25 >= 25) {
                bal25 -= 25; 
                bal50 += 50;
            } else {
                flag = false;
                break;
            }
        } 
        else if (x == 100) {
            if (bal50 >= 50 && bal25 >= 25) {
                bal50 -= 50; 
                bal25 -= 25;
            } else if (bal25 >= 75) {
                bal25 -= 75;
            } else {
                flag = false;
                break;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    solve();
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}