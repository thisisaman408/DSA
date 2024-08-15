#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end(), greater<long long>()); 
        for (int i = 1; i < n; i++) {
            long long increase = min(k, a[0] - a[i]);
            a[i] += increase;
            k -= increase;
            if (k == 0) break;
        }
        long long sumAlice = 0, sumBob = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) sumAlice += a[i];
            else sumBob += a[i];
        }
        cout << sumAlice - sumBob << endl;
    }

    return 0;
}
