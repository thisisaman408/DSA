#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m;
    cout << "Enter rows of 1st matrix : " << endl;
    cin >> m;
    int n;
    cout << "Enter columns of 1st matrix : " << endl;
    cin >> n;
    int p;
    cout << "Enter rows of 2nd matrix : " << endl;
    cin >> p;
    int q;
    cout << "Enter columns of 2nd matrix : " << endl;
    cin >> q;
    if (n == p)
    {
        int a[m][n];
        cout << "Enter elements of 1st matrix : " << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int b[p][q];
        cout << "Enter elements of 2nd matrix : " << endl;
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cin >> b[i][j];
            }
        }
        // for multiplication res[i][j] = a[i][0]*b[0][j] + a[i][1]*b[0][j]
        //  res[i][j] = summation of a[i][r]*b[r][j] from r = 0 to r = n - 1 or p -1
        // thus for multiplication
        int res[m][q];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                res[i][j] = 0;
                for (int k = 0; k < p; k++)
                {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        cout << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Matrices cannot be multiplied" << endl;
    }
}