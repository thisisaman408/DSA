#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int> pos; 

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pos[v[i]] = i + 1; 
    }

    int m;
    cin >> m;
    vector<int> s(m);
    for (int i = 0; i < m; i++) cin >> s[i];

    long long lswaps = 0;
    long long rswaps = 0;
    
    for (int x : s) {
        int index = pos[x];
        lswaps += index;         
        rswaps += n - index + 1;  
    }

    cout << lswaps << " " << rswaps << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
