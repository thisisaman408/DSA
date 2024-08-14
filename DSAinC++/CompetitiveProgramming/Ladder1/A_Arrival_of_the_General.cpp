#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

const int INF = 1e9;
const int NEGINF = -1e9;
const int MOD = 1e9 + 7;

#define ll long long
#define lli long long int


vector<int> a;
int swap_count = 0;
int n;

void my_swap(int *i, int *j){
    int temp = 0;
    temp =*i;
    *i =*j;
    *j = temp;
}
void solve()
{
    int mx = a[0];
    int max_idx = 0;
    int min_idx = n-1;
    for(int i = 1; i< n;i++){
          if(a[i] > mx){
            mx = a[i];
            max_idx = i;
          }
    }
    swap_count = max_idx;
    mx = a[n-1];
    for(int i = n-2; i>= 0;i--){
          if(a[i] < mx){
            mx = a[i];
            min_idx = i;
          }
    }
    if(max_idx == 0 and min_idx == n-1){
        swap_count = 0;
        return;
    }
    if (min_idx < max_idx) swap_count += (n - 1 - min_idx - 1); 
    else swap_count += (n - 1 - min_idx);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    solve();
    cout<<swap_count;

    return 0;
}