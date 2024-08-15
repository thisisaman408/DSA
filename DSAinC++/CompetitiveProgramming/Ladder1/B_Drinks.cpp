#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include<cstring>
#include<string.h>
#include <iomanip>

using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int

int arr[100];
void solve() {
    int n;
    cin>>n;
    int x= n;
    ll sum = 0;
    while(x--){
        int x;
        cin>>x;
        sum +=x;
    }
    cout<<fixed<<setprecision(12)<<((sum)/(n*100.0))*100;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}