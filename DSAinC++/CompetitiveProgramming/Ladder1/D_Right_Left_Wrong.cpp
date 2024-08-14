#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        vector<char> s(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        
        // Initialize variables to track sums
        int closestSum = 0;
        int farthestSum = 0;
        
        // Find closest L and R
        int leftL = -1;
        int rightR = -1;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                leftL = i;
            } else if (s[i] == 'R' && leftL != -1) {
                rightR = i;
                // Calculate sum from leftL to rightR
                int sum = 0;
                for (int k = leftL; k <= rightR; ++k) {
                    sum += a[k];
                }
                closestSum = max(closestSum, sum);
                leftL = -1; // Reset leftL after finding a valid pair
            }
        }
        
        // Find farthest L and R
        int rightL = -1;
        int leftR = -1;
        
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'R') {
                leftR = i;
            } else if (s[i] == 'L' && leftR != -1) {
                rightL = i;
                // Calculate sum from rightL to leftR
                int sum = 0;
                for (int k = rightL; k <= leftR; ++k) {
                    sum += a[k];
                }
                farthestSum = max(farthestSum, sum);
                leftR = -1; // Reset leftR after finding a valid pair
            }
        }
        
        // Output the maximum score
        cout << closestSum + farthestSum << endl;
    }
    
    return 0;
}
