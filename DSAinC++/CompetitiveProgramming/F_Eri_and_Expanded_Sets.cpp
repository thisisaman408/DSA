#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int countBrilliantSubarrays(const vector<int>& a) {
    int n = a.size();
    int result = 0;

    // Iterate over each possible starting index of the subarray
    for (int start = 0; start < n; ++start) {
        unordered_set<int> elements;
        int minVal = INT_MAX, maxVal = INT_MIN;

        // Expand the window from the starting index
        for (int end = start; end < n; ++end) {
            elements.insert(a[end]);
            minVal = min(minVal, a[end]);
            maxVal = max(maxVal, a[end]);

            // Check if the set of elements is consecutive
            if (maxVal - minVal + 1 == elements.size()) {
                result++;
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << countBrilliantSubarrays(a) << endl;
    }

    return 0;
}
