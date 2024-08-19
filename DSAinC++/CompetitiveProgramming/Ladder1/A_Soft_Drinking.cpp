#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include<cstring>
#include<string.h>

using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int

void solve() {
    int n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int totalDrink = k*l;
    int totalSlice = d*c;
    int totalSalt = p;
    int totalToast = 0;


    int drinkToasts = totalDrink / (n * nl);
    int limeToasts = totalSlice / n;
    int saltToasts = totalSalt / (n * np);


    cout<< min(drinkToasts,min(limeToasts,saltToasts))<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}