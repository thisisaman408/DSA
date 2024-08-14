#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > arr(3, vector<int>(3, 1));

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int a;
            cin >> a;
            if (a % 2 != 0) {
                arr[i][j] = 1 - arr[i][j];
                if (i + 1 < 3) arr[i + 1][j] = 1 - arr[i + 1][j]; 
                if (i - 1 >= 0) arr[i - 1][j] = 1 - arr[i - 1][j]; 
                if (j + 1 < 3) arr[i][j + 1] = 1 - arr[i][j + 1]; 
                if (j - 1 >= 0) arr[i][j - 1] = 1 - arr[i][j - 1];
            }
        }
    }

    // Output the final state of the grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}
