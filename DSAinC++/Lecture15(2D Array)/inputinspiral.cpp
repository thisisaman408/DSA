#include <iostream>
#include <vector>
using namespace std;
void spiralmatrix(vector<vector<int> > &v)
{
    int m = v.size();
    int n = v[0].size();
    int minr = 0;
    int maxr = m - 1;
    int minc = 0;
    int maxc = n - 1;
    while (minc <= maxc && minr <= maxr)
    {
        // right
        for (int j = minc; j <= maxc; j++)
        {
            cin >> v[minr][j];
        }
        minr++;
        // down
        
        for (int i = minr; i <= maxr; i++)
        {
            cin >> v[i][maxc];
        }

        maxc--;
        // left
        for (int j = maxc; j >= minc; j--)
        {
            cin >> v[maxr][j];
        }
        maxr--;
        // up
        for (int i = maxr; i >= minr; i--)
        {
            cin >> v[i][minc];
        }
        minc++;
    }
}
int main()
{
    int m;
    cout << "Enter rows : " << endl;
    cin >> m;
    int n;
    cout << "Enter columns : " << endl;
    cin >> n;
    vector<vector<int> > a(m, vector<int>(n));
    cout << "Enter elements : " << endl;
    spiralmatrix(a);
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
    }
}