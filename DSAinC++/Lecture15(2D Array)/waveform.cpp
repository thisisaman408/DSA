#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    int matrix[m][n];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Wave form of the matrix: ";
    for (int j = 0; j < n; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                cout << matrix[i][j] << " ";
            }
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }

    cout << endl;

    return 0;
}
