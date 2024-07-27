#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));

        // Read the matrix 'a'
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        // Flatten the matrix 'a' into a 1D array
        vector<int> flat_a;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                flat_a.push_back(a[i][j]);
            }
        }

        // Rotate the flattened array by more than 1 position
        vector<int> flat_b(flat_a.size());
        int shift = max(1, (int)flat_a.size() / 2); // Ensure shift is at least 1
        for (int i = 0; i < flat_a.size(); i++)
        {
            flat_b[(i + shift) % flat_a.size()] = flat_a[i];
        }

        // Convert the rotated 1D array back into a 2D matrix 'b'
        vector<vector<int>> b(n, vector<int>(m));
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                b[i][j] = flat_b[index++];
            }
        }

        // Check if the matrix 'b' is valid
        bool isValid = true;
        for (int i = 0; i < n && isValid; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == b[i][j])
                {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << b[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
