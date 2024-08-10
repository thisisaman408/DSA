#include <iostream>
#include <vector>
using namespace std;

vector<unsigned long long> factorials(101, 1); // Store factorials up to 100

void precomputeFactorials(int maxP) {
    for (int i = 1; i <= maxP; ++i) {
        factorials[i] = factorials[i-1] * i;
        if (factorials[i] > 1e18) { // Prevent overflow issues
            break;
        }
    }
}

int main() {
    int P;
    cin >> P;

    precomputeFactorials(P);

    int count = 0;
    for (int p = 0; p <= P; ++p) {
        for (int n = 0; n <= 9; ++n) {
            if (p != n * p && factorials[p] == n * p) {
                ++count;
            }
        }
    }

    cout << count << endl;
    return 0;
}
