#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int m;
    cout << "Enter rows : " << endl;
    cin >> m;
    int n;
    cout << "Enter columns : " << endl;
    cin >> n;
    int a[m][n];
    cout << "Enter the elemlents of the matrix" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "The matrix given by you is as follows" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j || i + j == n - 1)
            {
                cout << a[i][j] << " ";
            }
        }
    }
}