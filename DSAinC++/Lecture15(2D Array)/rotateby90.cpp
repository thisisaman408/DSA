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
    cout << endl;
    int minr = 0;
    int maxr = m - 1;
    int minc = 0;
    int maxc = n - 1;
    while (maxc >= 0)
    {
        for (int i = minr; i <= maxr; i++)
        {
            cout << a[i][maxc] << " ";
        }
        cout << endl;
        maxc--;
    }
}